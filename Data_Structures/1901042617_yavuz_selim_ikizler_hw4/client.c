#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#define BUFFER_SIZE 1024

int client_pipe_fd;
int server_pipe_fd;

void sigintHandler(int sig) {
    char close_msg[] = "close";
    write(client_pipe_fd, close_msg, sizeof(close_msg));
    printf("\nfd:%d\n", client_pipe_fd);
    exit(0);
}



int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <Connect/tryConnect> <ServerPID>\n", argv[0]);
        exit(1);
    }

  //  const char *connection_option = argv[1];
    const char *server_pid = argv[2];

    server_pipe_fd = open("/tmp/server_pipe", O_WRONLY);
    if (server_pipe_fd == -1) {
        perror("open");
        exit(1);
    }

    client_pipe_fd = open("/tmp/client_pipe", O_RDONLY);
    if (client_pipe_fd == -1) {
        perror("open");
        exit(1);
    }

    //write(server_pipe_fd, argv[2], strlen(argv[2]));

   

    char buffer[BUFFER_SIZE];
    int is_quit = 0;

    //char pid_msg[BUFFER_SIZE];
     
    memset(buffer,0,BUFFER_SIZE);
   
    printf("Connected to server (PID: %s). Enter your commands:\n", server_pid);

    signal(SIGINT,sigintHandler);

    while (!is_quit) {
        printf("> ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';  // Remove newline character

        if (write(server_pipe_fd, buffer, strlen(buffer)) == -1) {
            perror("Failed to send instruction to the server");
            break;
        }

        char response[BUFFER_SIZE] = {0};
        if (read(client_pipe_fd, response, BUFFER_SIZE) <= 0) {
            printf("Connection failed \n");
            //break;
        }

        if (strncmp(response, "quit", 4) == 0) {
            is_quit = 1;
        } else {
            printf("%s\n", response);
        }
    }

    close(client_pipe_fd);
    close(server_pipe_fd);
    return 0;
}