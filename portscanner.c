/*
    Port scanner code in C
*/

#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv){

    struct hostent *host;
    struct servent *service;
    int err, i, sock, start, end;
    char hostname[100];
    struct sockaddr_in sa;

    // Get the hostname to scan
    printf("Enter hostname or IP: ");
    fgets(hostname, sizeof(hostname), stdin);
    hostname[strcspn(hostname, "\n")] = 0;

    printf("\n");

    // Get start port number
    printf("Enter start port number: ");
    scanf("%d", &start);

    printf("\n");

    // Get end port number
    printf("Enter end port number: ");
    scanf("%d", &end);

    // Initialise the sockaddr_in structure    
    memset(&sa, 0, sizeof sa);
    sa.sin_family = AF_INET;

    // direct ip address, use it
    if(isdigit(hostname[0])){
        sa.sin_addr.s_addr = inet_addr(hostname);
    }
    else if ( (host = gethostbyname(hostname)) != 0){
        strncpy((char*)&sa.sin_addr, (char*) host->h_addr, sizeof sa.sin_addr);
    }
    else {
        herror(hostname);
        exit(2);
    }

    // Start the port scan loop
    printf("Starting the port scan loop: \n");
    for( i = start; i <= end; i++){

        sa.sin_port = htons(i);
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if(sock < 0){
            exit(1);
        }

        err = connect(sock, (struct sockaddr*)&sa, sizeof sa);

        service = getservbyport(htons(i), "tcp");
        char *svc_name = service ? service->s_name : "unknown";

        if(err == 0){
            printf("%-10d %-10s %-20s\n", i, "open", svc_name);
        }

        close(sock);
        
    }

    printf("\nDone.\n"),
    fflush(stdout);
    return 0;

}