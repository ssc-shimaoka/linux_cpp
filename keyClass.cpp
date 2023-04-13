#include "keyClass.h"

// コンストラクタ
Key::Key(int roomNo){
    _roomNo = roomNo;
    _status = 0;
}

// open
int Key::open(){
    if(_status == 1)
    {
        std::cout << "key opened" << std::endl;
        return -1;
    }

    std::cout << "key open" << std::endl;
    _status = 1;

    return 0;
}

// close
int Key::close(){
    if(_status == 0)
    {
        std::cout << "key closed" << std::endl;
        return -1;
    }

    std::cout << "key close" << std::endl;
    _status = 0;

    return 0;
}

int Key::getRoomNo(){
    return _roomNo;
}

int Key::getStatus(){
    return _status;
}