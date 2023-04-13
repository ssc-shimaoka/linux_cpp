#include "roomClass.h"

// コンストラクタ
Room::Room(int roomNo){
    _roomNo = roomNo;
}

int Room::getRoomNo(){
    return _roomNo;
}

int Room::open(int keyNo){
    if(keyNo != _roomNo)
    {
        std::cout << "この部屋の鍵と違います" << std::endl;
        return -1;
    }
    return Key::open();
}

