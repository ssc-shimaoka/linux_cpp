#include <memory>
#include <iostream>
#include <string>

class Shape{
    protected:
    int mData;
    std::string mName;

    public:
    Shape(int data):mData(data), mName("Shape") {}

    int getData(){return mData;}
    virtual std::string& getName(){return mName;}
};

class Square:public Shape{
  std::string mName;

  public:
  Square(int data):Shape(data), mName("Square"){}

  int getData(){return Shape::mData;}
  std::string& getName() override {return mName;}
};

class Circle:public Shape{
  std::string mName;

  public:
  Circle(int data):Shape(data), mName("Circle"){}

  int getData(){return Shape::mData;}
  std::string& getName() override {return mName;}
};

int main()
{

    Circle c(10);
    Shape* pC = &c;
    std::cout << "Data: " << pC->getData() << ", Name: " << pC->getName() << std::endl;

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