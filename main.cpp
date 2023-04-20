#include <iostream>
#include <filesystem>
#include <cassert>

using namespace std ;

int main()
{
  // 現在の作業ディレクトリを取得
  filesystem::path p = filesystem::current_path();
  cout << p << endl;

  // 現在の作業ディレクトリを設定
  filesystem::current_path("/tmp");
  cout << filesystem::current_path() << endl;

  // フルパスに変換
  filesystem::path p2 = filesystem::absolute("a.txt");
  cout << p2 << endl;

  // ディレクトリを作成
  bool result = filesystem::create_directory("dir");
  cout << "dir作成" << endl;

  assert(result);  // 作成処理が正常に処理されれば、エラーにならない（事前にディレクトリが存在するとエラー）
  assert(filesystem::exists("dir")); // 存在する場合、エラーにならない
  assert(filesystem::is_directory("dir"));  // ディレクトリの場合、エラーにならない

  // すでに存在するディレクトリを指定した場合、falseは返るがエラーにはならない
  bool result2 = filesystem::create_directory("dir");
  cout << "dir作成2回め" << endl;
  assert(!result2); // 失敗するとエラーにならない（！）

  return 0;
}