#include <memory>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <future>

using namespace std;

//----------------------------------------------------
//observerインターフェース定義
//----------------------------------------------------
class Observer{
  public:
  virtual void Update() = 0;
};

//----------------------------------------------------
//observer実装クラス
//----------------------------------------------------
class MyObserver: public Observer{
  public:
  void Update() override;
  int getloopFlag();
  private:
  int loopFlg = 1;
};

void MyObserver::Update(){
  cout << "非同期処理 完了通知されました" << endl;
  loopFlg = 0;
}

int MyObserver::getloopFlag(){return loopFlg;}

//----------------------------------------------------
//sujectクラス
//----------------------------------------------------
class Subject{
  public:
  void AddObserver(Observer& observer);
  void AsyncProcess();
  void Nofify();

  private:
  std::vector<Observer*> observers_;
};

void Subject::AddObserver(Observer& observer){
  this->observers_.push_back(&observer);
}

void Subject::AsyncProcess(){
  //非同期処理実装
  //std::thread t([&]{ 
  auto t = std::async(std::launch::async, []{
    cout << "別スレッド処理 sleep実施直前" << endl;
    sleep(3); 
    cout << "別スレッド処理 sleep実施完了" << endl;
  });
 
  //非同期完了待ち（無限待ち状態　設定箇所）
  //t.join();
  t.get();
  Nofify();
}

void Subject::Nofify(){
  for(int i =  0; i < this->observers_.size(); i++){
    this->observers_[i]->Update();
  }
}

//----------------------------------------------------
//main関数
//----------------------------------------------------
int main()
{
  MyObserver myobserver;
  Subject subject;

  int x = 0;
  cout << "main Start" << endl;

  subject.AddObserver(myobserver);
  subject.AsyncProcess();

  while(myobserver.getloopFlag() == 1){
    cout << "main loop" << endl;
    //subject.AsyncProcess();
  }

  //subject.Nofify();

  cout << "main End" << endl;
  return 0;
}

