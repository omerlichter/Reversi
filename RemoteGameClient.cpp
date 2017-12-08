#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "RemoteGameClient.h"

using namespace std;

RemoteGameClient::RemoteGameClient(const char *serverIP, int serverPort):
        serverIP_(serverIP), serverPort_(serverPort),
        clientSocket_(0) {
}

int RemoteGameClient::connectToServer() {
    // Create a socket point
    this->clientSocket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (this->clientSocket_ == -1) {
        throw "Error opening socket";
    }

    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(this->serverIP_, &address)) {
        throw "Can't parse IP address";
    }

    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof(address), AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }

    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(this->serverPort_);

    // Establish a connection with the TCP server
    if (connect(this->clientSocket_, (struct sockaddr
    *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout << "Connected to server" << endl;
    cout << "waiting for other player to join..." << endl;

    //-----------------------------------
    // read the player number from server
    int playerNumber;
    int stat = read(this->clientSocket_, &playerNumber, sizeof(playerNumber));
    if (stat == -1) {
        throw "Error read playerNumber from socket";
    }
    return playerNumber;
}

int RemoteGameClient::sendToServer(const char *moveBuff) const {
    // send the buffer to the server
    int stat = write(this->clientSocket_, moveBuff, 10);
    if (stat == -1) {
        throw "Error writing moveBuff to socket";
    }
    return 0;
}

int RemoteGameClient::getFromServer(char *moveBuff) const {
    // read the buffer from server
    int stat = read(this->clientSocket_, moveBuff, 10);
    if (stat == -1) {
        throw "Error reading moveBuff from socket";
    }
    return 0;
}
