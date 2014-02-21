#ifndef NETINTERFACE_H
#define NETINTERFACE_H

class NetInterface
{
public:
    NetInterface();

    bool checkFieldHasBoat(int xx, int yy);

    //Maybe I need a Boolean here
    bool sendCheckFieldHasBoat(int xx, int yy);

    void readyToPlay(bool ready);

    void gameStart();


};

#endif // NETINTERFACE_H
