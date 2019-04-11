#include <iostream>

using namespace std;
/*
 * 工厂模式和简单工厂模式要求产品子类必须要是同一类型的，拥有共同的方法，这就限制了产品子类的扩展。
 * 而抽象工厂是可以生产同一类型的多个产品的，
 */

//产品类型基类
class TV{
public:
    TV(){}
    virtual ~TV(){}
};

class TVA : public TV{
public:
    TVA(){
        cout << "TV(brand A) is produced..." << endl;
    }
};

class TVB : public TV{
public:
    TVB(){
        cout << "TV(brand B) is produced..." << endl;
    }
};

class AirCondition{
public:
    AirCondition(){}
    virtual ~AirCondition(){}
};

class AirConditionA : public AirCondition{
public:
    AirConditionA(){
        cout << "AirCondition(brand A) is produced..." << endl;
    }
};

class AirConditionB : public AirCondition{
public:
    AirConditionB(){
        cout << "AirCondition(brand B) is produced..." << endl;
    }
};

//一个工厂生产一系列不同类型的产品
class Factory{
public:
    Factory(){}
    virtual TV* createTV() = 0;
    virtual AirCondition* createAC() = 0;
};
//A厂生产产品为A的电视和洗衣机
class AFactory : public Factory{
public:
    TV* createTV(){
        return new TVA();
    }
    AirCondition* createAC(){
        return new AirConditionA();
    }
};

class BFactory : public Factory{
public:
    TV* createTV(){
        return new TVB();
    }
    AirCondition* createAC(){
        return new AirConditionB();
    }
};


int main(int argc, char *argv[])
{
    //A工厂生产产品
    Factory* aFactory = new AFactory();
    TV* tva = aFactory->createTV();
    AirCondition* aca = aFactory->createAC();

    //B工厂生产产品
    Factory* bFactory = new BFactory();
    TV* tvb = bFactory->createTV();
    AirCondition* acb = bFactory->createAC();
    return 0;
}
