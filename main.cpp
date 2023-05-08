#include <memory>
#include <iostream>
#include <functional>

struct Tax
{
    /* data */
    std::function<std::string()> desc;
    std::function<float()> rate;
};

class Income
{
private:
    /* data */
public:
    static std::string desc(){return "Income ";}
    static float valueCoeff(){return 0.2f;}
};

class Resident
{
private:
    /* data */
public:
    static std::string desc(){return "Resident ";}
    static float valueCoeff(){return 0.15f;}
};

class Cumulative
{
private:
    /* data */
public:
    static std::string desc(){return "Cumulative ";}
    static float valueCoeff(){return 0.30f;}
};

template<class T>
static T accumulateOne(std::function<T()> call, std::function<T()> next)
{
    std::cout << "One way arg function is called." << '\n';

    if(next){
        return call() + next();
    }else{
        return call();
    }
};

template<typename T, typename U>
static auto accumulateTwo(T t,U u)
{
    std::cout << "Two way arg function is called." << '\n';

    if(u){
        return t() + u();
    }else{
        return t();
    }
};


int main()
{
    Tax tax;

    //tax.desc = [=] {return accumulateOne<std::string>(&Income::desc, tax.desc);};
    tax.desc = [=] {return accumulateTwo(&Income::desc, tax.desc);};
    tax.desc = [=] {return accumulateTwo(&Resident::desc, tax.desc);};
    tax.desc = [=] {return accumulateTwo(&Cumulative::desc, tax.desc);};

    //tax.rate = [=] {return accumulateTwo(&Income::valueCoeff, tax.rate);};
    tax.rate = [=] {return accumulateOne<float>(&Income::valueCoeff, tax.rate);};
    tax.rate = [=] {return accumulateTwo(&Resident::valueCoeff, tax.rate);};
    tax.rate = [=] {return accumulateTwo(&Cumulative::valueCoeff, tax.rate);};

    std::cout << tax.desc() << "tax" << std::endl;
    std::cout << tax.rate() << "chaged" << std::endl;

    return 0;
}