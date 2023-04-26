#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

// グローバル領域にmtxを用意
std::mutex mtx;

void worker() {
    // 共通の資源（ここでは標準出力）を使う前にロックをかける
    mtx.lock();

    std::cout << "lock!" << std::endl;
    // 資源を使った処理を行う
    std::cout << "thread id: " << std::this_thread::get_id() << std::endl;

    // 使い終わったらロックを外す
    mtx.unlock();
    std::cout << "Unlock!" << std::endl;
}

int main() {

    // スレッドを4つ作る
    std::vector<std::thread> ths(4);
    for (auto& th : ths) {
        th = std::thread(worker);
    }

    // すべてのスレッドが終わるのを待つ
    for (auto& th : ths) {
        th.join();
    }

    return 0;
}