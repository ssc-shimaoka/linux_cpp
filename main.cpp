#include <memory>
#include <iostream>
#include "keyClass.h"

int main()
{
    Key* ptr = new Key(501);
    std::cout << "部屋番号は" << ptr->getRoomNo() << std::endl;

    return 0;
}