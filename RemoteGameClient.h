#ifndef REVERSI_REMOTEGAMECLIENT_H
#define REVERSI_REMOTEGAMECLIENT_H


class RemoteGameClient {
public:
    /**
     * constructor
     * @param serverIP - ip of the server
     * @param serverPort - port of the server
     */
    RemoteGameClient(const char *serverIP, int serverPort) ;
    /**
     * connect to the server
     * @return the player number in the game
     */
    int connectToServer() ;
    /**
     * send message to server
     * @param moveBuff - buffer with the move
     * @return 0 if succeed
     */
    int sendToServer(const char* moveBuff) const ;
    /**
     * get message from server
     * @param moveBuff - buffer for write to
     * @return if succeed
     */
    int getFromServer(char* moveBuff) const ;

private:
    const char *serverIP_;
    int serverPort_;
    int clientSocket_;
};


#endif //REVERSI_REMOTEGAMECLIENT_H
