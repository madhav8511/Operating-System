#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int sd, new_sd;
    struct sockaddr_in serv, clie;
    char buffer[MAX_BUFFER_SIZE] = {0};

    // Create socket
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv.sin_port = htons(5555);

    // Bind socket to address
    if (bind(sd, (struct sockaddr *)&serv, sizeof(serv)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sd, 5) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", 5555);

    // Handle incoming connections
    while (1)
    {

        int address_len = sizeof(clie);

        // Accept new connection
        if ((new_sd = accept(sd, (struct sockaddr *)&clie, (socklen_t *)&address_len)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        int pid = fork();
        if (pid == 0)
        {

            printf("Handling client from %s:%d\n", inet_ntoa(clie.sin_addr), ntohs(clie.sin_port));
            int read_size = read(new_sd, buffer, MAX_BUFFER_SIZE);

            printf("Received message from client: %s\n", buffer);

            // Send message to client
            char *message = "Hello from server\n";
            int write_size = write(new_sd, message, strlen(message));

            printf("Sent message to client: %s\n", message);

            close(new_sd);
            exit(EXIT_SUCCESS);
        }
        else
        {
            close(new_sd);
        }
    }
    close(sd);
    return 0;
}