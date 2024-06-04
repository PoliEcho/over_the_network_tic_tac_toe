#include "global.hpp"
#include "net.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <fstream>

using std::cout;
using std::cin;
using std::cerr;
using std::string;



void handshake_failed() {
    cerr << "handshake failed";
    exit(3);
}

int init_net() {

    //buffer to send and receive messages with
    char msg[1500];

    if (ishost) {
        //code for host

        //setup a socket and connection tools
        sockaddr_in servAddr;
        bzero((char *)&servAddr, sizeof(servAddr));
        servAddr.sin_family = AF_INET;
        servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servAddr.sin_port = htons(port);

        //open stream oriented socket with internet address
        //also keep track of the socket descriptor
        int serverSd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSd < 0) {
            cerr << "Error establishing the server socket\n";
            return 2;
        }
        //bind the socket to its local address
        int bindStatus = bind(serverSd, (struct sockaddr *)&servAddr,
                              sizeof(servAddr));
        if (bindStatus < 0) {
            cerr << "Error binding socket to local address\n";
            return 2;
        }
        cout << "Waiting for a guest to connect...\n";
        //listen for up to 5 requests at a time
        listen(serverSd, 5);
        //receive a request from client using accept
        //we need a new address to connect with the client
        sockaddr_in newSockAddr;
        socklen_t newSockAddrSize = sizeof(newSockAddr);
        //accept, create a new socket descriptor to
        //handle the new connection with client
        int newSd = accept(serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
        if (newSd < 0) {
            cerr << "Error accepting request from guest\n";
            return 2;
        }
        cout << "Connected with guest!\n";
        //lets keep track of the session time
        struct timeval start1, end1;
        gettimeofday(&start1, NULL);
        //also keep track of the amount of data sent as well
        int bytesRead, bytesWritten = 0;

        memset(&msg, 0, sizeof(msg)); //clear the buffer
        bytesRead += recv(newSd, (char *)&msg, sizeof(msg), 0);
        if (strcmp(msg, "concheck") != 0) {
            handshake_failed();
        }

        string data = std::to_string(board_size);
        memset(&msg, 0, sizeof(msg)); //clear the buffer
        strcpy(msg, data.c_str());
        bytesWritten += send(newSd, (char *)&msg, strlen(msg), 0);

        memset(&msg, 0, sizeof(msg)); //clear the buffer
        bytesRead += recv(newSd, (char *)&msg, sizeof(msg), 0);
        if (board_size != std::stoi(msg)) {
            handshake_failed();
        }

        data = std::to_string(length);
        memset(&msg, 0, sizeof(msg)); //clear the buffer
        strcpy(msg, data.c_str());
        bytesWritten += send(newSd, (char *)&msg, strlen(msg), 0);

        memset(&msg, 0, sizeof(msg)); //clear the buffer
        bytesRead += recv(newSd, (char *)&msg, sizeof(msg), 0);
        if (length != std::stoi(msg)) {
            handshake_failed();
        }

    } else {
        // code for client
        const char *serverIp = serverIp_str.c_str();
        //setup a socket and connection tools
        struct hostent *host = gethostbyname(serverIp);
        sockaddr_in sendSockAddr;
        bzero((char *)&sendSockAddr, sizeof(sendSockAddr));
        sendSockAddr.sin_family = AF_INET;
        sendSockAddr.sin_addr.s_addr =
            inet_addr(inet_ntoa(*(struct in_addr *)*host->h_addr_list));
        sendSockAddr.sin_port = htons(port);
        int clientSd = socket(AF_INET, SOCK_STREAM, 0);
        //try to connect...
        int status = connect(clientSd,
                             (sockaddr *)&sendSockAddr, sizeof(sendSockAddr));

        if (status < 0) {
            cout << "Error connecting to socket!\n";
            return 2;
        }

        cout << "Connected to the host!\n";
        int bytesRead, bytesWritten = 0;
        struct timeval start1, end1;
        gettimeofday(&start1, NULL);

        string data;
        data = "concheck";
        memset(&msg, 0, sizeof(msg)); //clear the buffer
        strcpy(msg, data.c_str());
        bytesWritten += send(clientSd, (char *)&msg, strlen(msg), 0);

        memset(&msg, 0, sizeof(msg)); //clear the buffer
        bytesRead += recv(clientSd, (char *)&msg, sizeof(msg), 0);
        board_size = std::stoi(msg);

        data = std::to_string(board_size);
        memset(&msg, 0, sizeof(msg)); //clear the buffer
        strcpy(msg, data.c_str());
        bytesWritten += send(clientSd, (char *)&msg, strlen(msg), 0);

        memset(&msg, 0, sizeof(msg)); //clear the buffer
        bytesRead += recv(clientSd, (char *)&msg, sizeof(msg), 0);
        length = std::stoi(msg);

        data = std::to_string(length);
        memset(&msg, 0, sizeof(msg)); //clear the buffer
        strcpy(msg, data.c_str());
        bytesWritten += send(clientSd, (char *)&msg, strlen(msg), 0);
    }

    return 0;
}
