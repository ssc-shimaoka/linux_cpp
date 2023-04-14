#include <iostream>
#include <memory>
#include <unistd.h>

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
public:
  // 正常終了時の処理
  void onSuccessInternal() override {
      std::cout << "非同期処理 正常終了" << std::endl;
  }

  // 異常終了時の処理
  void onErrorInternal(const std::string& message) override {
      std::cout << "非同期処理 異常終了: " << message << std::endl;
  }
};

//---------------------------------------------------------------------
/*
 * 非同期処理クラス
*/
class Messenger {
  private:
  std::unique_ptr<MessegeHandler> handler_;
  int _loopFlg = 1;
 
 public:
  Messenger() = default;
  ~Messenger() = default;
  
  // コールバック登録
  void setHandler(std::unique_ptr<MessegeHandler> handler) {
    handler_ = std::move(handler);
  }

  // 非同期処理要求
  void sendMessage(const std::string& message) {
    // 引数の文字が0文字だった場合、異常終了
    if (message.size() == 0) {
      if (handler_) {
        handler_->onError("なにか入力してください");
      }
        
      return ;
    }

    // 時間のかかる処理
    sleep(5);

    // 正常終了時
    if (handler_) {
        _loopFlg = 0;
      handler_->onSuccess();
    }
  }

  int getLoopFlg() {
    return _loopFlg;
  }
};

//---------------------------------------------------------------------
/*
 * main
*/
int main() {
  //インスタンス生成
  auto messenger = std::make_unique<Messenger>();
  auto handler = std::make_unique<MessegeHandlerImple>();

  //コールバック登録 (メッセージハンドラ権限　移譲)
  messenger->setHandler(std::move(handler));

  while(messenger->getLoopFlg())
  {
    //非同期処理要求（異常系）
    messenger->sendMessage("");

    //非同期処理要求（正常系）
    messenger->sendMessage("start");
   }

  return 0;
}