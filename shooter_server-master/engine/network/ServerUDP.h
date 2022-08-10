//
// Created by Neirokan on 30.04.2020
//

#ifndef ENGINE_SERVERUDP_H
#define ENGINE_SERVERUDP_H

#include "ReliableMsg.h"
#include "UDPSocket.h"
#include <memory>
#include <set>

class ServerUDP
{
protected:
    UDPSocket _socket;
    double _lastBroadcast;
    bool _working;

    bool process();
    bool timeout(sf::Uint16 id);

    std::set<sf::Uint16> _clients{};
public:
    explicit ServerUDP();
    [[nodiscard]] bool isWorking() const;
    bool start(sf::Uint16 port);
    void stop();
    void update();

    virtual void updateInfo(){};

    // virtual functions
    virtual void broadcast(){};

    // here you have to send Init message _back to 'targetId' and send NewClient message to all '_clients'
    virtual void processConnect(sf::Uint16 senderId){};
    virtual void processClientUpdate(sf::Uint16 senderId, sf::Packet& packet){};
    virtual void processDisconnect(sf::Uint16 senderId){};

    virtual void processCustomPacket(sf::Packet& packet, sf::Uint16 senderId){};

    virtual void processStop(){};

    virtual ~ServerUDP();
};


#endif //INC_3DZAVR_SERVERUDP_H