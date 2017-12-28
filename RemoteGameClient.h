#ifndef REVERSI_REMOTEGAMECLIENT_H
#define REVERSI_REMOTEGAMECLIENT_H

#include <string.h>

using namespace std;

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
    void connectToServer() ;
    /**
     * send message to server
     * @param moveBuff - buffer with the move
     * @return 0 if succeed
     */
    int sendToServer(const string& message) const ;
    /**
     * get message from server
     * @param moveBuff - buffer for write to
     * @return if succeed
     */
    string getFromServer() const ;

private:
    const char *serverIP_;
    int serverPort_;
    int clientSocket_;
};


#endif //REVERSI_REMOTEGAMECLIENT_H
