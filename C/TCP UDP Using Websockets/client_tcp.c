#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 12345

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddress;
    char buffer[MAX_BUFFER_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "Failed to initialize winsock.\n");
        return 1;
    }

    // Create socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        fprintf(stderr, "Failed to create socket.\n");
        WSACleanup();
        return 1;
    }

    // Prepare the server address structure
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddress.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        fprintf(stderr, "Failed to connect to server.\n");
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Send message to the server
    if (send(clientSocket, "Hello server!", strlen("Hello server!"), 0) == SOCKET_ERROR) {
        fprintf(stderr, "Failed to send data.\n");
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Receive response from the server
    if (recv(clientSocket, buffer, MAX_BUFFER_SIZE, 0) == SOCKET_ERROR) {
        fprintf(stderr, "Failed to receive data.\n");
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Print received message
    printf("Received message from server: %s\n", buffer);

    // Close the socket
    closesocket(clientSocket);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}
