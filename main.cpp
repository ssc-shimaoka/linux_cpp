#include <iostream>
#include <string>
#include <vector>

class my_container {
public:
  int *begin() {
    return &buf[0];
  }
  int *end() {
    return &buf[5];
  }

private:
  int buf[5] = {21, 22, 23, 24, 25};
};

int main(int, char**) {
  //ユーザ定義のクラスに対して範囲for文を使う
  my_container mc;

  std::cout << "For my_container: " << std::endl;
  for (auto& e : mc) {
    std::cout << "  " << e << std::endl;
  }

  return 0;
}