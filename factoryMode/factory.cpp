#include <iostream>

using namespace std;
/*
 * 工厂模式
 * 当有新的产品产生时，只要按照抽象产品角色、抽象工厂角色提供的合同来生成，
 * 将简单工厂的内部逻辑判断转移到了客户端代码来进行
 * 降低耦合性，符合开闭原则，当添加一种产品的时候不会去修改已有的代码
 * */

//产品基类
class Product{
public:
    Product(){}
    virtual ~Product(){}
};

class TV : public Product{
public:
    TV(){
        cout << "TV is produced..." << endl;
    }
};

class WashingMachine : public Product{
public:
    WashingMachine(){
        cout << "WashingMachine is produced..." << endl;
    }
};

class AirCondition : public Product{
public:
    AirCondition(){
        cout << "AirCondition is produced..." << endl;
    }
};

class Factory{
public:
    Factory(){}
    virtual ~Factory(){}
    virtual Product* createProduct(){}
};

/*
 * 一个子类对应一个工厂类
 *原本会因为业务代码而庞大的简单工厂类，拆分成了一个个的工厂类，这样代码就不会都耦合在同一个类里了。
 * */
class TVFactory : public Factory{
public:
     Product* createProduct(){
        return new TV();
    }
};

class WashingMachineFactory : public Factory{
public:
     Product* createProduct(){
        return new WashingMachine();
    }
};

class AirConditionFactory : public Factory{
public:
     Product* createProduct(){
        return new AirCondition();
    }
};


int main02(int argc, char *argv[])
{
    //一个工厂生产一件物品
    Factory* tvFactory = new TVFactory();
    Product* tv = tvFactory->createProduct();

    Factory* wmFactory = new WashingMachineFactory();
    Product* wm = wmFactory->createProduct();

    Factory* acFactory = new AirConditionFactory();
    Product* ac = acFactory->createProduct();

    return 0;
}
