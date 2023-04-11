#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple> //タプル

struct MyInt
{
    int value;
    /* data */
};

//operator...[<]の演算子を独自のものに上書きしている。
bool operator<(const MyInt& a, const MyInt& b) noexcept
{
    return a.value < b.value;
}

struct Person
{
    int id;
    int age;
    std::string name;
    /* data */
};

bool operator<(const Person& a, const Person& b) noexcept
{
    return std::tie(a.id, a.age, a.name) < std::tie(b.id, b.age, b.name);
}




int main(int, char**) {
    std::map<MyInt, int> m1{
        {MyInt{1}, 3},
        {MyInt{2}, 1},
        {MyInt{3}, 4},
    };
    std::cout << m1[MyInt{2}]  << std::endl;
    //追加
    std::cout << m1[MyInt{3}]  << std::endl;

    std::map<Person, int> m2{
        {Person{1, 18, "Alice"}, 3},
        {Person{2, 30, "Bob"}, 1},
        {Person{3, 30, "carol"}, 5},
    };
    std::cout << m2[Person{2,30,"Bob"}]  << std::endl;
    //追加
    std::cout << m2[Person{1,18,"Alice"}]  << std::endl;
}