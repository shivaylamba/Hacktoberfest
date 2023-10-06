#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 12345

int main() {
    WSADATA wsaData;
    SOCKET serverSocket;
    struct sockaddr_in serverAddress, clientAddress;
    int clientAddressLength = sizeof(clientAddress);
    char buffer[MAX_BUFFER_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "Failed to initialize winsock.\n");
        return 1;
    }

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        fprintf(stderr, "Failed to create socket.\n");
        WSACleanup();
        return 1;
    }

    // Prepare the server address structure
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(SERVER_PORT);

    // Bind socket to server address
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        fprintf(stderr, "Failed to bind socket.\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("UDP server running on port %d.\n", SERVER_PORT);

    // Receive and send messages
    while (1) {
        // Receive message from client
        if (recvfrom(serverSocket, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&clientAddress, &clientAddressLength) == SOCKET_ERROR) {
            fprintf(stderr, "Failed to receive data.\n");
            closesocket(serverSocket);
            WSACleanup();
            return 1;
        }

        // Print received message
        printf("Received message from client: %s\n", buffer);

        // Send message back to client
        if (sendto(serverSocket, "21BCE0787 - UwU, Hi!", strlen("21BCE0787 - UwU, Hi!"), 0, (struct sockaddr*)&clientAddress, clientAddressLength) == SOCKET_ERROR) {
            fprintf(stderr, "Failed to send data.\n");
            closesocket(serverSocket);
            WSACleanup();
            return 1;
        }
    }

    // Cleanup and close socket
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}