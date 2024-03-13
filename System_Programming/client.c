#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <dirent.h>
#include <sys/stat.h>
#include <signal.h>
#define BUFFER_SIZE 1024
#define MAX_FILES 1024
#define MAX_BUFFER_SIZE 1000
#define MAX_FILENAME_LENGTH 256
typedef struct {
    char source[MAX_FILENAME_LENGTH];
    char destination[MAX_FILENAME_LENGTH];
    char file_name_source[MAX_FILENAME_LENGTH];
    int source_descripter;
    int destination_descripter;
} FileSave;

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
void sync_directories(int client_sock, char* server_directory);
int check_differance(FileSave * prev,int *prev_size , FileSave* current,int curr_size,file_info* file_arr,int* file_number);
void read_dir(DIR*dir,const char* sourceDir,FileSave * buffer,int * bufferIndex);
void read_folder(FileSave* read_file , char* sourceDir,int *size);
void change_server(file_info *file_list,int file_number,int client_sock,char * client_directory);
void handle_sigint(int sig);




int bufferIndex = 0;
int main(int argc, char *argv[]) {
    int client_sock, port_no;
    struct sockaddr_in server_addr;
    struct hostent *server;
    int buffer_size=0;
    int buffer_size2=0;
    char buffer[BUFFER_SIZE];
    FileSave * before;
    FileSave * after;
    file_info * file_arr;
    int file_number=0;
    if (argc < 4) {
        fprintf(stderr,"usage: %s dirName port\n", argv[0]);
        exit(1);
    }
    signal(SIGINT, handle_sigint);
    port_no = atoi(argv[2]);
    client_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (client_sock < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[3]);

    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    server_addr.sin_port = htons(port_no);

    if (connect(client_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    // TO-DO: Handle file synchronization and updates here.
    // This might involve sending a request to the server and waiting for a response.
    // Example 2: Update a file
    //char filename[] = "file.txt";
    //send_request(client_sock, "UPDATE", filename);
   // update_file(client_sock, filename);
    //char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%d", getpid());
    
     write(client_sock, buffer, strlen(buffer) + 1);

    memset(buffer, 0, sizeof(buffer));
     read(client_sock, buffer, sizeof(buffer) - 1);
     printf("%s \n",buffer);
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
    
  
  
  sync_directories(client_sock,argv[1]);
     before = ( FileSave*)malloc(MAX_BUFFER_SIZE * sizeof( FileSave));
     
    read_folder(before,argv[1],&buffer_size);
    
    while(1){
        after=( FileSave*)malloc(MAX_BUFFER_SIZE * sizeof( FileSave));
        file_arr=( file_info*)malloc(MAX_BUFFER_SIZE * sizeof( file_info));
        read_folder(after,argv[1],&buffer_size2);
        
       if( check_differance(before,&buffer_size,after,buffer_size2,file_arr,&file_number)){
            change_server(file_arr,file_number,client_sock,argv[1]);
       }
       else{ 
        sync_directories(client_sock,argv[1]);
        for(int i=0;i<buffer_size;i++){
            close(before[i].source_descripter);
        }
        free(before);
        buffer_size=0;
        
        before=( FileSave*)malloc(MAX_BUFFER_SIZE * sizeof( FileSave));
        read_folder(before,argv[1],&buffer_size);
       }
        
       free(after);
       free(file_arr);
       file_number=0;
        buffer_size2=0;
        sleep(10);
    }
    
    close(client_sock);

    return 0;
}

void change_server(file_info *file_list,int file_number,int client_sock,char * client_directory){
    
    Command client_data;
    strcpy(client_data.client_directory,client_directory);
    strcpy(client_data.command,"change");
    for(int i=0;i<file_number;i++){
        client_data.send_file[i]=file_list[i];
    }
    
   // printf("\n%s\n",client_data.send_file[0].file_name);
    client_data.file_number=file_number;
    send(client_sock, &client_data, sizeof(Command), 0);
 
    char buffer[BUFFER_SIZE];  
    memset(buffer, 0, sizeof(buffer));
    read(client_sock, buffer, sizeof(buffer) - 1);
    printf("%s \n",buffer);
}

int check_differance(FileSave * prev,int *prev_size , FileSave* current,int curr_size,file_info * file_arr,int *file_number){
int include=0;
int equal;
int returned=0;
int c1,c2;
char buf1[BUFFER_SIZE];
char buf2[BUFFER_SIZE];
 char ch1, ch2;
 ssize_t bytesRead1, bytesRead2;
for(int i=0;i<curr_size;i++){
include=0;

equal = 1;
    for(int j=0;j<*prev_size;j++){
        if(strcmp(current[i].source,prev[j].source)==0){
             while (((bytesRead1 = read(current[i].source_descripter, &ch1, sizeof(char))) == sizeof(char)) &&
                    ((bytesRead2 = read(prev[j].source_descripter, &ch2, sizeof(char))) == sizeof(char))) {
                if (ch1 != ch2) {
                     equal=0; // Files are not equal
                }
            }
       /* if(bytesRead2!=bytesRead1){
            equal=0;
        }*/
    // If both files have reached the end
    
         //  printf("read bytes:%ld %ld ",bytesRead1,bytesRead2);

            include=1;
        }

    }
    if(!include){
        strcpy(file_arr[*file_number].file_name,current[i].source);
        strcpy(file_arr[*file_number].status,"add");
        strcpy(file_arr[*file_number].f_name,current[i].file_name_source);
        *file_number+=1;
        returned=1;
      //  printf("yeni eklenen dosya:%s \n",current[i].source);
    }
    if(!equal){
        strcpy(file_arr[*file_number].file_name,current[i].source);
        strcpy(file_arr[*file_number].status,"change");
        strcpy(file_arr[*file_number].f_name,current[i].file_name_source);
        *file_number+=1;
        returned=1;
      //  printf("the file %s change \n",current[i].source);
    }


    
}

for(int i=0;i<*prev_size;i++){
include=0;

equal = 1;
    for(int j=0;j<curr_size;j++){
        if(strcmp(current[j].source,prev[i].source)==0){
             
       /* if(bytesRead2!=bytesRead1){
            equal=0;
        }*/
    // If both files have reached the end
    
         //  printf("read bytes:%ld %ld ",bytesRead1,bytesRead2);

            include=1;
        }

    }
    if(!include){
        strcpy(file_arr[*file_number].file_name,prev[i].source);
        strcpy(file_arr[*file_number].status,"remove");
        strcpy(file_arr[*file_number].f_name,prev[i].file_name_source);
        *file_number+=1;
        returned=1;
      //  printf("removed file:%s \n",prev[i].source);
    }
    
    


    
}

if(returned){
        for(int i=0;i<*prev_size;i++){
           close(prev[i].source_descripter);
        }
        for(int i=0;i<curr_size;i++){
            prev[i].source_descripter=current[i].source_descripter;
            strcpy(prev[i].source,current[i].source);
            strcpy(prev[i].file_name_source,current[i].file_name_source);
        }
        *prev_size=curr_size;
    }

    return returned;
}
void handle_sigint(int sig) {
    // TO-DO: Close the server and cleanup when the SIGINT signal is received.
    printf("Shutting down client\n");
    exit(0);
}
void read_folder(FileSave* read_file , char* sourceDir,int *size){

    DIR* dir;
    struct dirent* entry;
    char sourcePath[MAX_FILENAME_LENGTH];
    char destPath[MAX_FILENAME_LENGTH];

    // Open source directory
    dir = opendir(sourceDir);
    if (dir == NULL) {
        perror("Error opening source directory");
       // pthread_exit(NULL);
    }
    

    if (read_file == NULL) {
        // Handle memory allocation error
        printf("Failed to allocate memory for buffer\n");
        return ;
    }
    read_dir(dir,sourceDir,read_file,size);


     //free(read_file);
}
void read_dir(DIR*dir,const char* sourceDir,FileSave * buffer,int * bufferIndex){
    struct dirent* entry;
    char sourcePath[MAX_FILENAME_LENGTH];
    char destPath[MAX_FILENAME_LENGTH];
    DIR* dir2;
    
      // Iterate over files in the source directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Create source and destination file paths
        snprintf(sourcePath, MAX_FILENAME_LENGTH, "%s/%s", sourceDir, entry->d_name);
        
        struct stat fileStat;
         if (stat(sourcePath, &fileStat) < 0) {
            printf("Unable to get file information for %s\n", entry->d_name);
            continue;
        }

      
    
        if(entry->d_type == DT_DIR){
           
    
    
    dir2=opendir(sourcePath);
    read_dir(dir2,sourcePath,buffer,bufferIndex);
    closedir(dir2);
    
        }
        else{

            // Wait if buffer is full
       
        // Copy file information into the buffer
        strcpy(buffer[*bufferIndex].source, sourcePath);
        strcpy(buffer[*bufferIndex].file_name_source,entry->d_name);
        
        // Open source file for reading
    buffer[*bufferIndex].source_descripter = open(buffer[*bufferIndex].source, O_RDONLY);
    if (buffer[*bufferIndex].source_descripter == -1) {
        perror("Error opening source file");
        return ;
    }

  
        
        *bufferIndex +=1;

        
    }
}
    
        
        
}
void sync_directories(int client_sock, char* client_directory) {
 
 
  Command client_data;
  strcpy(client_data.client_directory,client_directory);
  strcpy(client_data.command,"SYNC");
  
  client_data.file_number=0;
  send(client_sock, &client_data, sizeof(Command), 0);
 
  char buffer[BUFFER_SIZE];  
  memset(buffer, 0, sizeof(buffer));
  read(client_sock, buffer, sizeof(buffer) - 1);
  printf("%s\n",buffer);
  
}
