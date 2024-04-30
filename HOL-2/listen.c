#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
	struct sockaddr_in client;
	int sd = socket(AF_INET, SOCK_STREAM ,0);
	client.sin_family = AF_INET;
    	client.sin_addr.s_addr = inet_addr("127.0.0.1");
    	client.sin_port = htons(5555);

    	connect(sd, (struct sockaddr *)&client, sizeof(client));
    
    // read/write
    char buf[100];
    write(1, "Sending message to server...\n", sizeof("Sending message to server...\n"));
    //sleep(1);
    write(sd, "Hi, I am client\n", sizeof("Message From client\n"));
    write(1, "Sent Successfully!\nPress return key to read...\n", sizeof("Sent Successfully!\nPress return key to read...\n"));
    getchar();
    int ret = read(sd, buf, sizeof(buf));
    write(1,"Message received from server : ",sizeof("Message received from server : "));
    write(1, buf, ret);
    
    close(sd);

    return (0);
}
