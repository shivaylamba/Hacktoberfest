#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 12345

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    int clientAddressLength = sizeof(clientAddress);
    char buffer[MAX_BUFFER_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "Failed to initialize winsock.\n");
        return 1;
    }

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
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

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        fprintf(stderr, "Failed to listen on socket.\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("TCP server running on port %d.\n", SERVER_PORT);

    // Accept client connection
    if ((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength)) == INVALID_SOCKET) {
        fprintf(stderr, "Failed to accept client connection.\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Receive message from client
    if (recv(clientSocket, buffer, MAX_BUFFER_SIZE, 0) == SOCKET_ERROR) {
        fprintf(stderr, "Failed to receive data.\n");
        closesocket(clientSocket);
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Print received message
    printf("Received message from client: %s\n", buffer);

    // Send message back to client
    if (send(clientSocket, "21BCE0787 - UwU!", strlen("21BCE0787 - UwU!"), 0) == SOCKET_ERROR) {
        fprintf(stderr, "Failed to send data.\n");
        closesocket(clientSocket);
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Close client socket
    closesocket(clientSocket);

    // Close server socket
    closesocket(serverSocket);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}
