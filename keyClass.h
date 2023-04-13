#ifndef KEYCLASS_H
#define  KEYCLASS_H
#include <iostream>

class Key
{
    private:
        int _status;

    public:
        Key();
        int open();
        int close();
        int getStatus();
};

#endif