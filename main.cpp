#include <memory>
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <condition_variable>
#include <functional>

std::condition_variable cv;
std::mutex cv_m;
bool task_completed =false;

class Observer{
    public:
    virtual void Notify() = 0;
};

class Subject{
    public:
    void Attach(Observer* obs){
        observer = obs;
    }

    void Notify(){
        observer->Notify();
    }

    private:
    Observer* observer;
};

class MainThread : public Observer{
    public:
    MainThread() {}

    void Notify() override{
        task_completed = true;
    }

    void run(Subject& subject){
        std::future<void> fut = std::async(std::launch::async, [&subject]{
            std::cout << "非同期処理 開始\n";
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::cout << "非同期処理 完了\n";

            subject.Notify();
        });

        while(true){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "main処理 実行\n";

            if(task_completed){
                std::cout << "mainスレッド 完了\n";
                break;
            }
        }

        fut.get();
    }
};


int main()
{
    std::cout << "アプリ開始\n";

    Subject subject;
    MainThread mainThread;

    subject.Attach(&mainThread);
    mainThread.run(subject);

    std::cout << "アプリ終了\n";

    return 0;
}