#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdbool.h>
#include <time.h>
#include <sys/stat.h>
#include <signal.h>
#define MAX_THREADS 5
#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

pthread_mutex_t commandMutex;
struct ThreadArgs {
    int client_sock;
    char* arg;
};
typedef struct{
    char file_name[MAX_FILENAME_LENGTH];
    char f_name[MAX_FILENAME_LENGTH];
    char status[MAX_FILENAME_LENGTH];
}file_info;
typedef struct {
    char client_directory[256];
    char command[256];
    file_info send_file[BUFFER_SIZE];
    int file_number;
} Command;
#define MAX_BUFFER_SIZE 200
#define MAX_FILENAME_LENGTH 256
typedef struct {
    char source[MAX_FILENAME_LENGTH];
    char destination[MAX_FILENAME_LENGTH];
    int source_descripter;
    int destination_descripter;
} FileCopyInfo;
int bufferIndex = 0;
FileCopyInfo *buffer;
volatile sig_atomic_t exit_flag = 0;
/*
void handle_sigint(int sig) {
    
    printf("Received SIGINT. Exiting...\n");
    exit_flag = 1;
}
*/
char change_file_list[MAX_BUFFER_SIZE][MAX_FILENAME_LENGTH];
int list_size=0;
int job_queu=0;
void *client_handler(void *client_sock);


void handle_sigint(int sig);


void handle_sync(char * sourceDir,char * destDir) ;

void read_dir(DIR*dir,DIR* dir_second,const char* sourceDir ,const char* destDir );
void handle_change(file_info* file_list,int file_number,char * directory);
int createPath(const char *path) ;
int createFile(const char *path, const char *path2);
void file_copy() ;
void copyFile(int sourceFd,int destFd, char* source, const char* destination);
int main(int argc, char *argv[]) {
    int server_sock, client_sock, port_no;
    struct sockaddr_in server_addr, client_addr;
    int max_thread=atoi(argv[2]);
    pthread_t threads[max_thread];
    socklen_t client_len = sizeof(client_addr);
    
    if (argc < 4) {
        fprintf(stderr,"usage: %s directory thread_pool_size port\n", argv[0]);
        exit(1);
    }
    signal(SIGINT, handle_sigint);
    port_no = atoi(argv[3]);
    struct stat st;
    if (stat(argv[1], &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
          //  printf("Directory already exists.\n");
           // return ;
        }
    }
    else{
        // Create the directory if it doesn't exist
    if (mkdir(argv[1], 0700) == 0) {
      //  printf("Directory created successfully.\n");
      
    } else {
        printf("Failed to create the directory.\n");
    }
    }
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Error opening socket");
        exit(1);
    }

    

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_no);
    
    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    listen(server_sock, 5);

    signal(SIGINT, handle_sigint);
    pthread_mutex_init(&commandMutex, NULL);
    int j = 0;
    while(1) {
        client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_len);
        if (client_sock < 0) {
            perror("Error on accept");
            exit(1);
        }
    
        struct ThreadArgs* threadArgs = malloc(sizeof(struct ThreadArgs));
        threadArgs->client_sock = client_sock;
        threadArgs->arg = argv[1];

        if (pthread_create(&threads[j], NULL, client_handler, (void*) threadArgs) < 0) {
            // Thread creation failed
            perror("pthread_create");
            // Handle the error
        }
       // pthread_join(threads[i], NULL);
        j++;
    }
     for (int i = 0; i < j; i++) {
        pthread_join(threads[i], NULL);
    }
    free(buffer);
    pthread_mutex_destroy(&commandMutex);
    return 0;
}

void *client_handler(void* args) {
    struct ThreadArgs* threadArgs = (struct ThreadArgs*) args;
      int sock = threadArgs->client_sock;
    char* directory = threadArgs->arg;
    char buffer[BUFFER_SIZE];
   // char client_directory[BUFFER_SIZE];

    // Initialize buffer
    memset(buffer, 0, sizeof(buffer));
     read(sock, buffer, sizeof(buffer) - 1);

    printf("The client connected with id: %s\n", buffer);

    
    snprintf(buffer, sizeof(buffer), "%s", directory);
     write(sock, buffer, strlen(buffer) + 1);
     while(1){
        
        Command client_data;
        // Lock the mutex before reading commands
       
        
      ssize_t bytes_received = recv(sock, &client_data, sizeof(Command), 0);
    if (bytes_received < 0) {
        fprintf(stderr, "Error occurred while receiving data.\n");
       // exit(1);
    }

    // Unlock the mutex after reading commands
        

   // printf("%s",client_data.client_directory);
    if(strncmp(client_data.command, "SYNC", 4) == 0){
        handle_sync(directory,client_data.client_directory);
        snprintf(buffer, sizeof(buffer), "%s", "update");
       write(sock, buffer, strlen(buffer) + 1);
    }
    if(strncmp(client_data.command, "change", 6) == 0){
       // printf("\n %s \n",client_data.send_file[0].file_name);
        strcpy(change_file_list[list_size],client_data.client_directory);
        list_size++;
        handle_change(client_data.send_file,client_data.file_number,directory);
        
        snprintf(buffer, sizeof(buffer), "%s", "changed");
       write(sock, buffer, strlen(buffer) + 1);
    }
       pthread_mutex_unlock(&commandMutex);  
        //sleep(1);
     }
     

    // Close the client socket
    close(sock);
    pthread_exit(NULL);
}
int createPath(const char *path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
           // printf("Directory '%s' already exists.\n", path);
            return 0;  // Directory already exists
        } else {
          //  printf("A file with the same name as '%s' already exists.\n", path);
            return -1;  // A file with the same name exists
        }
    }
    int result = mkdir(path, 0777);  // Create directory with read, write, and execute permissions for everyone
    if (result == 0) {
        printf("Directory '%s' created successfully.\n", path);
        return 0;
    } else {
        printf("Failed to create directory '%s'.\n", path);
        return -1;
    }
}
int createFile(const char *path,const char *path2) {
    int file = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int file2=open(path2, O_RDONLY);
    
    if (file != -1) {
        char buf[BUFFER_SIZE];
        ssize_t bytesRead, bytesWritten;
       // printf("File '%s' created successfully.\n", path);
        while ((bytesRead = read(file2, buf, sizeof(buf))) > 0) {
         
        bytesWritten = write(file, buf, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to destination file");
            break;
        }
    }
        close(file);
        return 0;
    } else {
        printf("Failed to create file '%s'.\n", path);
        return -1;
    }
    close(file);
}
void handle_change(file_info* file_list,int file_number,char * directory){
    job_queu++;
     pthread_mutex_lock(&commandMutex);

char operate_file[MAX_FILENAME_LENGTH];
char full_path[MAX_FILENAME_LENGTH];
    for(int i=0;i<file_number;i++){
        char* slash = strchr(file_list[i].file_name, '/');
            if (slash != NULL) {
            char* start = slash + 1;  // Skip the slash character
            memmove(operate_file, start, strlen(start) + 1);  // Move the remaining string
            }
            strcpy(full_path,directory);
            strcat(full_path,"/");
            strcat(full_path,operate_file);
        if(strcmp(file_list[i].status,"remove")==0){
             
            // Check if the file exists
            if (remove(full_path) == 0) {
              //  printf("File '%s' removed successfully.\n", full_path);
            } else {
                printf("File '%s' does not exist or could not be removed.\n", full_path);
            }
        }
        else if(strcmp(file_list[i].status,"add")==0){
             char *ptr = NULL;
             char dirPath[256];
            strncpy(dirPath, full_path, sizeof(dirPath));
            // Create directories
        for (ptr = strchr(dirPath + 1, '/'); ptr != NULL; ptr = strchr(ptr + 1, '/')) {
            *ptr = '\0';  // Null-terminate the path at the delimiter
        createPath(dirPath);
        *ptr = '/';   // Restore the delimiter
        
    }

    // Create the file
    createFile(full_path,file_list[i].file_name);
        }
        else if(strcmp(file_list[i].status,"change")==0){
            createFile(full_path,file_list[i].file_name);
        }
        else{
       // printf("invalid operation \n");
        }
    }

    pthread_mutex_unlock(&commandMutex);
}

void handle_sync(char * sourceDir,char * destDir) {
     pthread_mutex_lock(&commandMutex);
    DIR* dir;
    DIR * dir2;
    
   

    dir = opendir(sourceDir);
    dir2=opendir(destDir);
    if (dir == NULL) {
        perror("Error opening source directory");
       // pthread_exit(NULL);
    }
    buffer = ( FileCopyInfo*)malloc(MAX_BUFFER_SIZE * sizeof( FileCopyInfo));

    if (buffer == NULL) {
        // Handle memory allocation error
        printf("Failed to allocate memory for buffer\n");
        return ;
    }
    read_dir(dir,dir2,sourceDir,destDir);
     

    file_copy();
    free(buffer);
  //  }
    
// Set done flag
/*
    done = 1;

    // Signal that buffer is not empty (to wake up waiting consumers)
    pthread_cond_broadcast(&bufferNotEmpty);
    pthread_mutex_unlock(&bufferMutex);

    // Close directory
    closedir(dir);

    pthread_exit(NULL);
    */
    pthread_mutex_unlock(&commandMutex);
}
void copyFile(int sourceFd,int destFd, char* source, const char* destination) {
    
    int buffer_size = 4096; // Example buffer size
    
    // Dynamically allocate the buffer
    char* buf = (char*)malloc(buffer_size * sizeof(char));

    if (buf == NULL) {
        // Handle memory allocation error
        printf("Failed to allocate memory for buffer\n");
        return ;
    }
    ssize_t bytesRead, bytesWritten;
    
    
    // Copy data from source to destination
    while ((bytesRead = read(sourceFd, buf, sizeof(buf))) > 0) {
         
        bytesWritten = write(destFd, buf, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to destination file");
            break;
        }
    }

    // Close files
    close(sourceFd);
    close(destFd);

    // Print completion message
    if (bytesRead == 0) {
      // printf("Copied: %s\n", source);
    } else {
        printf("Error copying: %s\n", source);
    }
     free(buf);
    buf = NULL;
     pthread_mutex_unlock(&commandMutex); 
}
void file_copy() {
    while (1) {
        // Wait if buffer is empty and not done
       
        // Exit if buffer is empty and done
        if (bufferIndex == 0 ) {
            
            break;
        }

        // Get file information from buffer
        FileCopyInfo fileCopy;
        memcpy(&fileCopy, &buffer[bufferIndex - 1], sizeof(FileCopyInfo));
        bufferIndex--;

        

        // Copy the file
        copyFile(fileCopy.source_descripter,fileCopy.destination_descripter, fileCopy.source, fileCopy.destination);
    }

    
}
void read_dir(DIR*dir,DIR* dir_second,const char* sourceDir ,const char* destDir ){
    struct dirent* entry;
    char sourcePath[MAX_FILENAME_LENGTH];
    char destPath[MAX_FILENAME_LENGTH];
    char file_list[MAX_BUFFER_SIZE][MAX_FILENAME_LENGTH];
    DIR* dir2;
    DIR* dir2_second;
   // printf("%s %s ",sourceDir,destDir);
      // Iterate over files in the source directory
      int j=0;
    while ((entry = readdir(dir)) != NULL) {
        
        // Skip "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Create source and destination file paths
        snprintf(sourcePath, MAX_FILENAME_LENGTH, "%s/%s", sourceDir, entry->d_name);
        snprintf(destPath, MAX_FILENAME_LENGTH, "%s/%s", destDir, entry->d_name);
        struct stat fileStat;
         if (stat(sourcePath, &fileStat) < 0) {
            printf("Unable to get file information for %s\n", entry->d_name);
            continue;
        }
        strcpy(file_list[j],entry->d_name);
        j++;
       
    
        if(entry->d_type == DT_DIR){
           
             struct stat st;
    if (stat(destPath, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
          //  printf("Directory already exists.\n");
           // return ;
        }
    }
    else{
        // Create the directory if it doesn't exist
    if (mkdir(destPath, 0700) == 0) {
      //  printf("Directory created successfully.\n");
      
    } else {
        printf("Failed to create the directory.\n");
    }
    }
    dir2_second=opendir(destPath);
    dir2=opendir(sourcePath);
    read_dir(dir2,dir2_second,sourcePath,destPath);
    closedir(dir2);
    closedir(dir2_second);
    
        }
        else{

            
        // Copy file information into the buffer
        strcpy(buffer[bufferIndex].source, sourcePath);
        strcpy(buffer[bufferIndex].destination, destPath);
        // Open source file for reading
    buffer[bufferIndex].source_descripter = open(buffer[bufferIndex].source, O_RDONLY);
    if (buffer[bufferIndex].source_descripter == -1) {
        perror("Error opening source file");
        return ;
    }

    // Create or truncate destination file for writing
    buffer[bufferIndex].destination_descripter= open(buffer[bufferIndex].destination, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (buffer[bufferIndex].destination_descripter== -1) {
        perror("Error opening destination file");
        close(buffer[bufferIndex].source_descripter);
        return ;
    }
        
        bufferIndex++;

        
    }
    
    
}

struct dirent* entry2;
   while ((entry2 = readdir(dir_second)) != NULL) {
        
        // Skip "." and ".." directories
        if (strcmp(entry2->d_name, ".") == 0 || strcmp(entry2->d_name, "..") == 0) {
            continue;
        }
        
         snprintf(destPath, MAX_FILENAME_LENGTH, "%s/%s", destDir, entry2->d_name);
         
        int include=0;
        for(int i=0;i<j;i++){
            
            if(strcmp(file_list[i],entry2->d_name)==0){
                include=1;
            }

        }
       
        if(include!=1){
            if (remove(destPath) == 0) {
               // printf("File '%s' removed successfully.\n", destPath);
            } else {
                printf("File '%s' does not exist or could not be removed.\n", destPath);
            }
        }
       
    } 
        
        
}

void handle_sigint(int sig) {
    // TO-DO: Close the server and cleanup when the SIGINT signal is received.
    printf("Shutting down server\n");
    exit(0);
}

