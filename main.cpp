#include <memory>
#include <iostream>
#include <string>
#include "roomClass.h"

int main()
{
    //Keyクラスのインスタンス作成(unique_ptr)
    //Room* room501 = new Room(501);
    std::unique_ptr<Room> room501 (new Room(501));
    std::cout << "作成した部屋番号は" << room501->getRoomNo() << std::endl;

    //Room* room502 = new Room(502);
    std::unique_ptr<Room> room502 (new Room(502));
    std::cout << "作成した部屋番号は" << room502->getRoomNo() << "\n" << std::endl;

    // 現在の状態取得1
    std::string keyStatus = (room501->getStatus() == 1 ? "オープン" : "クローズ");
    std::cout << "501室の鍵の状態は" << keyStatus << std::endl;

    // open処理
    room501->open(503);
    room502->open(502);

    // 現在の501室の状態取得
    keyStatus = (room501->getStatus() == 1 ? "オープン" : "クローズ");
    std::cout << "501室の鍵の状態は" << keyStatus << std::endl;

    // 現在の502室の状態取得
    keyStatus = (room502->getStatus() == 1 ? "オープン" : "クローズ");
    std::cout << "502室の鍵の状態は" << keyStatus << std::endl;

    // openの状態でopen処理実行
    room502->open(502);

    return 0;
}
