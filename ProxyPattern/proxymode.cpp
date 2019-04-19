#include <iostream>
#include <unistd.h>
using namespace std;

//抽象角色：指代理角色和真实角色对外提供的公共方法，一般为一个接口。
class SaleBook{
public:
    virtual void Sale() = 0;
};
//真实角色：需要实现抽象角色接口，定义了真实角色所要实现的业务逻辑，
//以便供代理角色调用，也就是真正的业务逻辑。
class BookShop : public SaleBook{
public:
    BookShop(){
        count = 0;
    }
    void Sale(){
        count++;
        cout << "sold " << count << " books" << endl;
    }
private:
    int count;
};
//初始化图书的数量
//int BookShop::count = 0;

class TaoBao : public SaleBook{
public:
    TaoBao(SaleBook* saleBook){
        this->saleBook = saleBook;
    }
    void Sale(){
        //加一部分其他操作
        cout << "advertise online....." << endl;
        int i = 0;
        while( i < 6){
            saleBook->Sale();
            sleep(0.5);
            i++;
        }
        cout << "express all books to somewhere" << endl;
    }

private:
    SaleBook* saleBook;
};

int main(int argc, char *argv[])
{
    SaleBook* bookShop = new BookShop();
    SaleBook*  taoBao = new TaoBao(bookShop);
    taoBao->Sale();
    return 0;
}
