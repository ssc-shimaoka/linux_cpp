// このソースをビルドすると、ビルドエラーの原因にassertのエラーメッセージが出る。
// /home/shimaoka/source/main.cpp:7:24: error: static assertion failed: バッファサイズが0です

#include <cstddef>

template <std::size_t SIZE>

class Buffer
{
    static_assert(SIZE > 0, "バッファサイズが0です");
private:

    /* data */
public:
    Buffer(/* args */);
    ~Buffer();

Buffer::Buffer(/* args */)
{
}

Buffer::~Buffer()
{
}
};

int main()
{
    Buffer<0> buf;
}