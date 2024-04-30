#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
    struct sockaddr_in serv, cli;
    int sd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(8080);
    
    bind(sd, (struct sockaddr *)&serv, sizeof(serv));
    listen(sd, 5);
    printf("Server start Listening....\n");

    int nsd;

    int len = sizeof(cli);
    nsd = accept(sd, (struct sockaddr *)&cli, &len);
    printf("Client request accepted\n");

    char buf[100];
    int ret;
    ret = read(nsd, buf, sizeof(buf));
    write(1,"Message received from client : ",sizeof("Message received from client : "));
    write(1, buf, ret);
    write(nsd, "Hi, I am server\n", sizeof("Message From server\n"));

    close(nsd);
    close(sd);

    return(0);
}