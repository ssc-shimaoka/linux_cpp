#include <iostream>
#include <memory>

/*
メッセージハンドラインターフェース
*/
class MessegeHandler {
 public:
  MessegeHandler() = default;
  virtual ~MessegeHandler() = default;

  void onSuccess() {
    onSuccessInternal();
  }

  void onError(const std::string& message) {
    onErrorInternal(message);
  }

 protected:
  virtual void onSuccessInternal() = 0;
  virtual void onErrorInternal(const std::string& message) = 0;
};

//---------------------------------------------------------------------
/*
 * メッセージハンドラ(実装)

   インターフェースを継承し、処理終了時の処理を実装
*/
class MessegeHandlerImple : public MessegeHandler {
private:
  int _loopflg = 1;

public:
  void onSuccessInternal() override {
      std::cout << "call OnCuccess()" << std::endl;
      _loopflg = 0;
  }

  void onErrorInternal(const std::string& message) override {
      std::cout << "call OnError(): " << message << std::endl;
  }

  int getLoopFlg()
  {
    return _loopflg;
  }
};

//---------------------------------------------------------------------
/*
 * 処理要求クラス
*/
class Messenger {
 public:
  Messenger() = default;
  ~Messenger() = default;

  void setHandler(std::unique_ptr<MessegeHandler> handler) {
    handler_ = std::move(handler);
  }

  void sendMessage(const std::string& message) {
    if (message.size() == 0) {
      if (handler_)
        handler_->onError("error message");
      return ;
    }

    // メッセージ送信処理など

    if (handler_)
      handler_->onSuccess();
  }

 private:
  std::unique_ptr<MessegeHandler> handler_;
};

//---------------------------------------------------------------------
/*
 * main
*/
int main() {
  //インスタンス生成
  auto messenger = std::make_unique<Messenger>();
  auto handler = std::make_unique<MessegeHandlerImple>();

  //コールバック登録
  messenger->setHandler(std::move(handler));

  while(handler->getLoopFlg())
  {
    //処理要求
    messenger->sendMessage("Send message");
  }

  return 0;
}