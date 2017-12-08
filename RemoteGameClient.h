#ifndef REVERSI_REMOTEGAMECLIENT_H
#define REVERSI_REMOTEGAMECLIENT_H


class RemoteGameClient {
public:
    RemoteGameClient(const char *serverIP, int serverPort) ;
    int connectToServer() ;
    int sendToServer(const char* moveBuff) const ;
    int getFromServer(char* moveBuff) const ;

private:
    const char *serverIP_;
    int serverPort_;
    int clientSocket_;
};


#endif //REVERSI_REMOTEGAMECLIENT_H
