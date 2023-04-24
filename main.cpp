#include <memory>
#include <iostream>
#include <string>

class Human {
  private :
  std::string _name;
  double _height;
  double _weight;

  public :
  //コンストラクタ
  Human(const std::string& name, double height ,double weight)
  : _name(name), _height(height), _weight(weight){}

  //名前の取得
  const std::string& get_name(){ return _name; }

  //BMI計算
  double cal_bmi() const {
    double bmi = _weight / (_height * _height / 1000);

    return bmi;
  }
};

int main()
{
  std::string name;
  double height;
  double weight;

  std::cout << "名前入力" << std::endl;
  std::cin >> name; 
  std::cout << "身長入力" << std::endl;
  std::cin >> height; 
  std::cout << "体重入力" << std::endl;
  std::cin >> weight; 

  Human human (name, height, weight);

  std::cout << human.get_name() << "さんのBMIは" << human.cal_bmi() << "です" << std::endl;
  return 0;
}