#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;
int main()
{

  try {
    bool is_error = true;

    // なんらかのエラーが発生した
    if (is_error) { 
      throw runtime_error("error!");
    } else {
        // 何もしない
    }
  }

  catch (exception& e) {
    // 例外を捕捉(// 実装定義のエラー内容を取得する)
    cout << e.what() << endl;
    return -1;
  }

  // 正常終了
  cout << "正常終了" << endl;
  return 0;
}
