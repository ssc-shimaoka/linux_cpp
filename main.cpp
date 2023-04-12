#include <iostream>
#include <iostream>
#include <stack>
#include <deque>
#include <type_traits>

//クラステンプレート
template <class T, class Container = std::deque<T>>
class movable_stack : public std::stack<T, Container> {
  using base = std::stack<T, Container>;

//指定した定数式が偽である場合はコンパイルエラーとなり、static_assertの第2引数で指定した文字列リテラルが診断メッセージとして出力される。
  static_assert(std::is_nothrow_default_constructible<T>{},"T must be nothrow default constructible");
  static_assert(std::is_nothrow_move_constructible<T>{},"T must be nothrow move constructible");

public:
  std::pair<T, bool> move_pop() noexcept //例外を送出する可能性があるか判定するnoexcept演算子
  {
    if (base::empty()) {
      return std::make_pair(T(), false);
    }

    T x = std::move(base::top());
    base::pop();
    return std::make_pair(std::move(x), true);
  }
};

int main(int, char**) {
  movable_stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);

  while (!s.empty()) {
    int next_value = s.move_pop().first;
    std::cout << next_value << std::endl;
  }

//追加
  std::cout << s.move_pop().first << std::endl; //[.first]はスタックの先頭を指している？？　これがないとコンパイルエラーとなる。
}