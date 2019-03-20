#include<iostream>
#include<string>
#include<mutex>
using namespace std;
class Singleton;

class Singleton{

private:
    Singleton(){}
    Singleton& operator =(const Singleton& ){}
public:
    static Singleton* getSingleton(){
        if(instance == NULL){
            mutex_.lock();
            instance = new Singleton();
            mutex_.unlock();
        }
        return instance;
    }

    void setX(int x){
        this->x = x;
    }

    int getX(){
        return x;
    }

    void printX(){
        cout << "x = " << x << endl;
    }

private:
     static Singleton* instance;
     static mutex mutex_;
     int x;

};

Singleton* Singleton::instance  = NULL;
mutex Singleton::mutex_;

int main(){
    Singleton* singleton1 = Singleton::getSingleton();
    singleton1->setX(6);
    Singleton* singleton2 = Singleton::getSingleton();
    singleton2->printX();
    int x = singleton2->getX() + 1;
    singleton1->setX(x);
    singleton1->printX();
    cout << (singleton1 == singleton2 ? "singleton和singleton2相同" : "singleton1和single不同" ) <<endl;
    return 0;
}

