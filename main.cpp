#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;
int main()
{
  vector<string> list;
  list.push_back("No1 test");
  list.push_back("No2 test");
  list.push_back("No3 test");

  list.insert(list.begin() + 1, "No0?");

  //最初の要素
  cout << *list.begin() << endl;

  size_t size = list.size();
  cout << size << endl;

  //最大サイズ取得
  size_t s = list.max_size();
  cout << s << endl;

// 範囲forで要素アクセス
  for(auto& i: list)
  {
    //operatorが範囲forの場合いらない
    //string& x = list[i];
    string x = i;
    cout << x << endl;
  }

  cout << "「at」にて要素取得" << endl;
  for(int i; i < list.size(); i++)
  {
    string y = list.at(i);
    cout << y << endl;
  }

  //全削除
  cout << "要素全削除" << endl;
  list.clear();
  assert(list.empty());

   for(int i; i < list.size(); i++)
  {
    string y = list.at(i);
    cout << y << endl;
  }


  return 0;
}
