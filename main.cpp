#include <memory>
#include <iostream>
#include <string>

// ベースクラス定義
class Shape{
    public:
    int mData;
    std::string mName;

    public:
    // コンストラクタ
    Shape(int data):mData(data), mName("Shape") {}

    int getData(){return mData;}
    virtual std::string& getName(){return mName;}
};

// 四角クラス定義
class Square:public Shape{
  std::string mName;

  public:
  // コンストラクタ
  Square(int data):Shape(data), mName("Square"){}

  int getData(){return Shape::mData;}
  std::string& getName() override {return mName;}
};

// 丸クラス定義
class Circle:public Shape{
  std::string mName;

  public:
  // コンストラクタ
  Circle(int data):Shape(data), mName("Circle"){}

  int getData(){return Shape::mData;}
  std::string& getName() override {return mName;}
};

int main()
{

    Circle c(10);
    Shape* pC = &c;
    std::cout << "Data: " << pC->getData() << ", Name: " << pC->getName() << std::endl;
    //std::cout << "Data: " << pC->Shape::mData << ", Name: " << pC->getName() << std::endl;

    Square p(20);
    Square* pP = &p;
    std::cout << "Data: " << pP->getData() << ", Name: " << pP->getName() << std::endl;

    // インスタンス作成
    Square x0(1), x1(2);
    Circle y0(3), y1(4);

    // 配列にインスタンスのポインター設定（親クラスとして追加）
    Shape* shape[] = {&x0,&x1,&y0,&y1};

    // 配列分、名前出力
    for(int i = 0; i<4; i++)
    {
        std::cout << "Name: " << shape[i]->getName() << std::endl;
    }

    return 0;
}