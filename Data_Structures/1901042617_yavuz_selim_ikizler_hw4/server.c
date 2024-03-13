#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <dirent.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <errno.h>
#include <pthread.h>

#define BUFFER_SIZE 2048
#define SHARED_MEM_PATH "/tmp/shared_memory"
#define MAX_LINE_LENGTH 1000
   char server_pipe_path[] = "/tmp/server_pipe";
    char client_pipe_path[] = "/tmp/client_pipe";


pthread_t threads[BUFFER_SIZE];
typedef struct {
    int max_clients;
    char* dir_name;
    int server_pipe_fd;
} ThreadParams;

sem_t *semaphore;
char** splitString(const char* str, int* numTokens) {
    char* tempStr = strdup(str);  // Create a copy of the input string
    char* token = strtok(tempStr, " ");
    char** tokens = NULL;
    *numTokens = 0;

    while (token != NULL) {
        (*numTokens)++;
        tokens = realloc(tokens, (*numTokens) * sizeof(char*));
        tokens[(*numTokens) - 1] = strdup(token);
        token = strtok(NULL, " ");
    }

    free(tempStr);
    return tokens;
}
void* client_handler(void* args) {
    ThreadParams* params = (ThreadParams*) args;

   // int max_clients = params->max_clients;
    char* dir_name = params->dir_name;
  //  int server_pipe_fd = params->server_pipe_fd;

    int client_counter = 0;
    char buffer[BUFFER_SIZE];

    // Create unique client ID
    char client_id[10];
    snprintf(client_id, 10, "client%02d", client_counter);
    printf("Client thread %lu connected as \"%s\"\n", pthread_self(), client_id);

    sem_wait(semaphore);

    int server_read_fd = open(server_pipe_path, O_RDONLY);
    if (server_read_fd == -1) {
        perror("open");
        exit(1);
    }

    int client_write_fd = open(client_pipe_path, O_WRONLY);
    if (client_write_fd == -1) {
        perror("open");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = read(server_read_fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) {
            usleep(1000);
            continue;
        }

        int numTokens;
        char** tokens = splitString(buffer, &numTokens);
        if (strcmp(tokens[0], "close") == 0) {
            printf("Kill signal from client %s... Terminating...\n", client_id);
            break;
        }

        if (strcmp(buffer, "list") == 0) {
               

                // Open the current directory
                DIR *dir = opendir(dir_name);
                if (dir == NULL) {
                    perror("Failed to open directory");
                    exit(0);
                }

                // Read the directory entries and send them to the client
                struct dirent *entry;
                char response[BUFFER_SIZE] = {0};
                while ((entry = readdir(dir)) != NULL) {
                    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                        continue;
                    strncat(response, entry->d_name, BUFFER_SIZE - strlen(response) - 1);
                    strncat(response, "\n", BUFFER_SIZE - strlen(response) - 1);
                }
               
                // Send the directory listing to the client
                write(client_write_fd, response, strlen(response) + 1);
                closedir(dir);
            }

            else if(strcmp(tokens[0], "writeT") == 0){
                  //  printf("sth\n");
            
         //   printf("%s - %s",tokens[1],tokens[2]);
           
            char * file_name=tokens[1];
            int num = atoi(tokens[2]);
            
            char file_path[BUFFER_SIZE];
         //   printf("sth\n");
            // Copy the directory name into the file path buffer
            strcpy(file_path, dir_name);

            // Concatenate the file name onto the end of the file path
            strcat(file_path, "/");
            strcat(file_path, file_name);
            // Print the resulting words array
            printf("%s",file_path);
            FILE* file = fopen(file_path, "r+");
    if (file == NULL) {
        file = fopen(file_path, "w+");
        if (file == NULL) {
            printf("Error: cannot create or open file '%s'\n", file_path);
            exit(1);
        }
    }

    // Move file pointer to the desired line number
    if ( numTokens== 4) {
        int current_line_number = 1;
        char line[MAX_LINE_LENGTH];

        while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
            if (current_line_number == num) {
                // Replace the line with the given string
                fseek(file, -strlen(line), SEEK_CUR);
                fprintf(file, "%s\n", tokens[3]);
                break;
            }
            current_line_number++;
        }

        // If the line number exceeds the current number of lines, append the string at the end
        if (current_line_number < num) {
            fseek(file, 0, SEEK_END);
            fprintf(file, "%s\n", tokens[3]);
        }
    } else {
        // Append the string at the end of the file
        fseek(file, 0, SEEK_END);
        fprintf(file, "%s\n", tokens[2]);
    }

    fclose(file);
    //exit(1);
           char response[BUFFER_SIZE] = {0};
            
                     snprintf(response, BUFFER_SIZE, "write operation done");
                  if (write(client_write_fd, response, strlen(response)) < 0) {
                        perror("write failed");
                        exit(EXIT_FAILURE);
                    }
                }

                else if(strcmp(tokens[0], "readF") == 0){
          //  printf("sth\n");
            
          //  printf("%s - %s",tokens[1],tokens[2]);
           
            char * file_name=tokens[1];
            int num = atoi(tokens[2]);
            
            char file_path[BUFFER_SIZE];
          //  printf("sth\n");
            // Copy the directory name into the file path buffer
            strcpy(file_path, dir_name);

            // Concatenate the file name onto the end of the file path
            strcat(file_path, "/");
            strcat(file_path, file_name);
            // Print the resulting words array
           // printf("%s",file_path);
            FILE *file = fopen(file_path, "r");
            if (file == NULL) {
                printf("Error: cannot open file '%s'\n", file_name);
                exit(1);
            }

    char line[MAX_LINE_LENGTH];
    int current_line_number = 1;
    int line_exist=0;
    char *newstr=malloc(MAX_LINE_LENGTH * sizeof(char));
    
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        
        if (current_line_number == num) {
            char response[BUFFER_SIZE] = {0};
          //  printf("%s", line);
           line_exist=1;
            
            snprintf(response, BUFFER_SIZE, "%s", line);
           
            if (write(client_write_fd, response, strlen(response)) < 0) {
                        perror("write failed");
                        exit(EXIT_FAILURE);
                    }
            //fclose(file);
            free(newstr);
            break;
            //exit(0);
        }else{
            strcat(line,"\n");
        strcat(newstr,line);
        }
        
        current_line_number++;
    }
    if (!line_exist) {
        char response[BUFFER_SIZE] = {0};
        snprintf(response, BUFFER_SIZE, "%s", newstr);
        
        if (write(client_write_fd, response, strlen(response)) < 0) {
                        perror("write failed");
                        exit(EXIT_FAILURE);
                    }
    }
    
    
    
    //printf("Error: line %d does not exist in file '%s'\n", line_number, filename);
    fclose(file);
    //exit(1);
            printf("Result:\n");
            for (int i = 0; i < numTokens; i++) {
                printf("%d: %s\n", i + 1, tokens[i]);
               // free(words[i]);
            }
           // free(words);
        }

         else if(strcmp(tokens[0], "quit") == 0){
                    // Send response
                    char response[BUFFER_SIZE] = {0};
                     snprintf(response, BUFFER_SIZE, "quit");
                  if (write(client_write_fd, response, strlen(response)) < 0) {
                        perror("write failed");
                        exit(EXIT_FAILURE);
                    }
                }
               else if(strncmp(tokens[0], "help", 4) == 0){
            // Send response
            

            char response[BUFFER_SIZE] = "list\n readF\n writeT\n upload\n download\n killServer\n";
           if (write(client_write_fd, response, strlen(response)) < 0) {
                        perror("write failed");
                        exit(EXIT_FAILURE);
                    }
        }       
        else if(strncmp(tokens[0], "download", 8) == 0){
           char file_path[BUFFER_SIZE];
            strcpy(file_path, dir_name);

            // Concatenate the file name onto the end of the file path
            strcat(file_path, "/");
            strcat(file_path, tokens[1]);
            FILE* destinationFile = fopen(file_path, "rb");

             
        if (destinationFile == NULL) {
            printf("Error: Failed to open destination file '%s'\n", file_path);
            fclose(destinationFile);
            return 0;
        }

        // Read from the source file and write to the destination file
        int file_size=0;
        
        char* buffer = malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        printf("Error: Failed to allocate memory for buffer\n");
       // fclose(sourceFile);
       char response[BUFFER_SIZE] = {0};
         snprintf(response, BUFFER_SIZE, "%s ", "buffer error");
    
        if (write(client_write_fd, response, strlen(response)) < 0) {
                        perror("write failed");
                        exit(EXIT_FAILURE);
                    }
    }
   FILE* sourceFile = fopen(tokens[1], "wb");
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, destinationFile)) > 0) {
        fwrite(buffer, 1, bytesRead, sourceFile);
        file_size += bytesRead;
    }
    // Close the files
        fclose(sourceFile);
        fclose(destinationFile);
        char response[BUFFER_SIZE] = {0};
        snprintf(response, BUFFER_SIZE, "%d %s ",file_size, "bytes transferred");
    
       if (write(client_write_fd, response, strlen(response)) < 0) {
                        perror("write failed");
                        exit(EXIT_FAILURE);
                    }
        free(buffer);
        }

                else if(strncmp(tokens[0], "upload", 6) == 0){

                    FILE* sourceFile = fopen(tokens[1], "rb");
              char file_path[BUFFER_SIZE];
          
            // Copy the directory name into the file path buffer
            strcpy(file_path, dir_name);

            // Concatenate the file name onto the end of the file path
            strcat(file_path, "/");
            strcat(file_path, tokens[1]);
               FILE* destinationFile = fopen(file_path, "wb");

               if (destinationFile == NULL) {
            printf("Error: Failed to open destination file '%s'\n", file_path);
            fclose(sourceFile);
            return 0;
        }

        // Read from the source file and write to the destination file
        int file_size=0;

        char* buffer = malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        printf("Error: Failed to allocate memory for buffer\n");
        fclose(sourceFile);
        return 0;
    }

    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
        file_size += bytesRead;
    }
    // Close the files
        fclose(sourceFile);
        fclose(destinationFile);
        char response[BUFFER_SIZE] = {0};
        snprintf(response, BUFFER_SIZE, "%d %s ",file_size, "bytes transferred");

        if (write(client_write_fd, response, strlen(response)) < 0) {
                        perror("write failed");
                        exit(EXIT_FAILURE);
                    }
        free(buffer);
    
        }

        for (int i = 0; i < numTokens; ++i) {
            free(tokens[i]);
        }
        free(tokens);
    }
    close(client_write_fd);
    close(server_read_fd);

    sem_post(semaphore); // Release the semaphore
    return NULL;
}


void handle_sigint(int sig) {
    // Handle SIGINT (Ctrl-C)
    printf("\nKill signal received. Terminating...\n");
    sem_close(semaphore);
    sem_unlink("/server_semaphore");
    exit(0);
}

void handle_sigchld(int sig) {
    // Handle SIGCHLD (child process terminated)
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dirname> <max. #ofClients>\n", argv[0]);
        exit(1);
    }

    int max_clients = atoi(argv[2]);
    if ((mkdir(argv[1], S_IRWXU | S_IRWXG | S_IRWXO) < 0) && (errno != EEXIST)) {
        perror("mkdir");
        exit(1);
    }

    signal(SIGINT, handle_sigint);

    printf("Server Started PID %d...\n", getpid());
    printf("Waiting for clients...\n");

 
    /*unlink(server_pipe_path);
    unlink(client_pipe_path);*/

    // Check if server_pipe_path already exists
    if (access(server_pipe_path, F_OK) == -1) {
        // Create server_pipe_path if it doesn't exist
        if (mkfifo(server_pipe_path, 0666) == -1) {
            perror("mkfifo");
            exit(1);
        }
    }
     
    // Check if client_pipe_path already exists
    if (access(client_pipe_path, F_OK) == -1) {
        // Create client_pipe_path if it doesn't exist
        if (mkfifo(client_pipe_path, 0666) == -1) {
            perror("mkfifo");
            exit(1);
        }
    }
    semaphore = sem_open("/server_semaphore", O_CREAT | O_EXCL, 0666, max_clients);
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        exit(1);
    }

    int server_pipe_fd = open(server_pipe_path, O_RDONLY );
    if (server_pipe_fd == -1) {
        perror("open");
        exit(1);
    }

    ThreadParams params;
    params.max_clients = atoi(argv[2]);
    params.dir_name = argv[1];  // Setting the directory name from argv
    params.server_pipe_fd = server_pipe_fd;
// Creating threads for client handling
    for(int i = 0; i < max_clients; i++) {
        if(pthread_create(&threads[i], NULL, client_handler, &params) != 0){
            perror("Failed to create thread");
            return 1;
        }
    }
// Joining the threads to wait for their completion
    for(int i = 0; i < max_clients; i++) {
        if(pthread_join(threads[i], NULL) != 0){
            perror("Failed to join thread");
            return 1;
        }
    }

    close(server_pipe_fd);
    sem_close(semaphore);
    sem_unlink("/server_semaphore");
    return 0;
}