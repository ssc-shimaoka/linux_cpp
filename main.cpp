#include <iostream>

template <class T>
class Stack
{
private:
    T* stack;
    int index;
public:
    Stack(int size) : index(0) { stack = new T[size]; }
    ~Stack() { delete [] stack; }
    void push(T item) { stack[index++] = item; }
    T pop() { return stack[--index]; }
};

int main(int, char**) {
    Stack<int> stack(256);
    stack.push(123);
    stack.push(456);
    // 出力
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
}