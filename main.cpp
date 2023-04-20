#include <iostream>
#include <filesystem>

using namespace std ;

int main()
{
  // 現在の作業ディレクトリを取得
  filesystem::path p = filesystem::current_path();
  cout << p << endl;

  // 現在の作業ディレクトリを設定
  filesystem::current_path("/tmp");
  cout << filesystem::current_path() << endl;
}