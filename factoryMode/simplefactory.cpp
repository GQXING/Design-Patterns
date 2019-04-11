#include <iostream>

using namespace std;
/*
 * 简单工程模式
 * 想要什么产品，这个工厂就可以创建这种产品。比如想要一台洗衣机。工厂就创建这台洗衣机。即工厂可以创建产品。
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
    virtual Product* createProduct(string name){}
};

class SimpleFactory : public Factory{
public:
     Product* createProduct(string name){
        if(name == "TV"){
            return new TV();
        }else if(name == "WashingMachine"){
            return new WashingMachine();
        }else if(name == "AirCondition"){
            return new AirCondition();
        }else{
            return NULL;
        }
    }
};


int main01(int argc, char *argv[])
{
    Factory* factory = new SimpleFactory();
    //用户在工厂中取走产品，而不是让用户来创建，从而降低用户和产品的耦合度。
    Product* tv = factory->createProduct("TV");
    Product* wm = factory->createProduct("WashingMachine");
    Product* ac = factory->createProduct("AirCondition");
    return 0;
}
