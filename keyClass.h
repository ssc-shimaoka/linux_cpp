#ifndef KEYCLASS_H
#define  KEYCLASS_H
#include <iostream>

class Key
{
    private:
        int _roomNo;
        int _status;

    public:
        Key(int roomNo);
        int open();
        int close();
        int getRoomNo();
        int getStatus();
};

#endif