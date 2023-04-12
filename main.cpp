#include <iostream>
#include <string>

struct Parameter {
  int id;
  std::string name;
};

class X {
  int id_;
  std::string name_;

public:
//コンストラクタ１
  X(int id, const std::string& name) : id_(id), name_(name)
  {
    std::cout << "invoked (1) constructor" << std::endl;
    std::cout << "invoked (1) name=" << name_ << std::endl;
  }

//コンストラクタ２
//コンストラクタ１に初期値を渡して初期化処理を委譲
//その後、２の処理が走る
  X(const Parameter& param) : X(param.id, param.name)
  {
    std::cout << "invoked (2) constructor" << std::endl;
    std::cout << "invoked (2) name=" << name_ << std::endl;
  }
};

int main()
{
  Parameter param;
  param.id = 3;
  param.name = "Alice";

  X x(param);
}