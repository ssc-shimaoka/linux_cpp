#include <memory>
#include <iostream>

int main()
{
    // shared_ptr生成
    std::shared_ptr<int> sharedPtr(new int(42));

    // shared_ptrを使ってリソースにアクセス
    int value = *sharedPtr;

    value = 10;
    std::cout << value << std::endl;

    // リソースの所有権の移譲
    std::shared_ptr<int> otherSharedPrt = sharedPtr;

    // カスタムデリータの指定
    std::shared_ptr<int> customDeleterSharedPrt(new int[10], [](int* p){
        delete[] p;
    });

    // std::weak_ptrと連携
    std::shared_ptr<int> sharedPtr1(new int(42));
    std::weak_ptr<int> weakPtr(sharedPtr1);

    return 0;
}