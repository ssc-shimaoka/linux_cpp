#include <memory>
#include <iostream>
#include <string>
#include "keyClass.h"

int main()
{
    //Keyクラスのインスタンス作成
    Key* ptr = new Key(501);
    std::cout << "部屋番号は" << ptr->getRoomNo() << std::endl;

    // 現在の状態取得1
    std::string keyStatus = (ptr->getStatus() == 1 ? "オープン" : "クローズ");
    std::cout << "現在の鍵の状態は" << keyStatus << std::endl;

    // open処理
    ptr->open();

    // 現在の状態取得2
    keyStatus = (ptr->getStatus() == 1 ? "オープン" : "クローズ");
    std::cout << "現在の鍵の状態は" << keyStatus << std::endl;

    // openの状態でopen処理実行
    ptr->open();

    return 0;
}
