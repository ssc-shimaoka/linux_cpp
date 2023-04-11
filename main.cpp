#include <iostream>
#include <string>

int main(int, char**) {
    std::cout << "Hello, world!\n";

    // 01:C++11 auto型推論
    auto word = "Hello, world2!\n";
    std::cout << word;

    // 02:decttype(変数)
    // あまり使い道がわからない・・・。
    //  sizeofにもdecttypeには丸括弧が必須
    auto i = 10;
    decltype(i) j = i;
    int m = sizeof (j);

    i = 40;
    std::cout << j << "," << i <<  "," << m << "byte\n";
}