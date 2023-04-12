#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    const int array[] = {1,2,3,4,5,6};
    //vectorはシーケンスコンテナの一種で、各要素は線形に、順序を保ったまま格納される。
    std::vector<int> v{array, array + 6};

    std::cout << "コンテナのサイズは" << v.size() << std::endl;

    //イテレータ範囲[first, last)から、条件を満たしている要素の数を数える。
    //条件面にてラムダ式を使っている
    auto c = std::count_if(v.begin(), v.end(), [](int elem) -> bool {return elem %2 == 0; });

    //条件に合うのは「2・4・6」の3つ
    std::cout << c << std::endl;
}