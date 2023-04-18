#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace::std;

//----------------------------------------------------
// ピザクラス
//----------------------------------------------------
class Pizza {
public:
    void setDough(const string dough) {
        dough_ = dough;
    }
    void setSauce(const string sauce) {
        sauce_ = sauce;
    }
    void setTopping(const string topping) {
        topping_ = topping;
    }
    void getInfo() const {
        cout << "生地は" << dough_ 
             << "で、 ソースは" << sauce_
             << " トッピングは" << topping_
             << "のピザを作った。" << endl;
    }
private:
    string dough_;   // パン生地
    string sauce_;   // ソース
    string topping_; // トッピング
};

//----------------------------------------------------
// ピザBuilder ベースクラス
//----------------------------------------------------
class AbstractPizzaBuilder {
public:
    virtual ~AbstractPizzaBuilder() {}
    unique_ptr<Pizza> getPizza() {
        return move(pizza_);
    }
    void createNewPizzaProduct() {
        pizza_ = make_unique<Pizza>();
    }
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;

protected:
    unique_ptr<Pizza> pizza_;
};

//----------------------------------------------------
// ハワイアンのピザBuilderクラス
//----------------------------------------------------
class HawaiianPizzaBuilder : public AbstractPizzaBuilder {
public:
    virtual ~HawaiianPizzaBuilder() override {}

    virtual void buildDough() override {
        pizza_->setDough("クロス");
    }
    
    virtual void buildSauce() override {
        pizza_->setSauce("マイルド");
    }
    
    virtual void buildTopping() override {
        pizza_->setTopping("ハムとパイナップル");
    }
};

//----------------------------------------------------
// スパイシーピザBuilderクラス
//----------------------------------------------------
class SpicyPizzaBuilder : public AbstractPizzaBuilder {
public:
    virtual ~SpicyPizzaBuilder() override {}

    virtual void buildDough() override {
        pizza_->setDough("焼いたパン");
    }

    virtual void buildSauce() override {
        pizza_->setSauce("辛い");
    }

    virtual void buildTopping() override {
        pizza_->setTopping("ペペロニとサラミ");
    }
};

//----------------------------------------------------
// インスタンスを生成するクラス
//----------------------------------------------------
class Cook {
public:
    Cook& setPizzaBuilder(unique_ptr<AbstractPizzaBuilder> pb) {
        pizzaBuilder_ = move(pb);
        return *this;
    }

    // 設定された型(クラス)に合わせて一気にインスタンスを生成し、さらにPizzaを返すクラス
    unique_ptr<Pizza> build() {
        pizzaBuilder_->createNewPizzaProduct(); // インスタンス生成
        pizzaBuilder_->buildDough();
        pizzaBuilder_->buildSauce();
        pizzaBuilder_->buildTopping();
        return pizzaBuilder_->getPizza();
    }
private:
    std::unique_ptr<AbstractPizzaBuilder> pizzaBuilder_;
};

//----------------------------------------------------
//メイン関数
//----------------------------------------------------
int main() {
    Cook cook;

    //ピザ作成
     Cook& pb1 = cook.setPizzaBuilder(std::make_unique<HawaiianPizzaBuilder>());
    unique_ptr<Pizza> hawaian = pb1.build();

    Cook& pb2 = cook.setPizzaBuilder(std::make_unique<SpicyPizzaBuilder>());
    unique_ptr<Pizza> spicy = pb2.build();
    
    //ピザ情報取得
    hawaian->getInfo();
    spicy->getInfo();
}