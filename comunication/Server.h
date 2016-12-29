#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include <iostream>
#include "Udp.h"
#include "TaxiCenterProtocol.h"

class Server {
protected:
    Protocol* protocol;
    Udp* udp;
public:
    char buffer[1024];
    Server(Protocol* protocol, Udp* udp): udp(udp), protocol(protocol){};
    ~Server();
    void initialize();
    void send(int numOfMsg);
    int receive(int scenario);
};


#endif //EX4_SERVER_H