#ifndef ROOMCLASS_H
#define  ROOMCLASS_H

#include <iostream>
#include<memory>
#include "keyClass.h"

class Room : public Key
{
    private:
        int _roomNo;

    public:
        Room(int roomNo);
        int getRoomNo();

        int open(int keyNo);
};

#endif