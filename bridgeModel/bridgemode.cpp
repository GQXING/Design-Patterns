#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
/*
 *  桥接模式——两种抽象角色：笔和颜色
 */

class Color{
public:
    Color(){}
    ~Color(){}
    virtual string getColor() = 0;
protected:
    string color_str;
};

class Pen{
public:
    Pen(){}
    ~Pen(){}
    virtual void draw() = 0;
protected:
    Color* color;
};

class Black : public Color{
public:
    Black(){
        color_str = "black";
    }
    string getColor(){
        return color_str;
    }
};

class Red : public Color{
public:
    Red(){
        color_str = "red";
    }
    string getColor(){
        return color_str;
    }
};

class Blue : public Color{
public:
    Blue(){
        color_str = "blue";
    }
    string getColor(){
        return color_str;
    }
};

class Brush : public Pen{
public:
    Brush(Color* color){
        this->color=color;
    }
    void draw(){
        cout<<"using "<<color->getColor()<<" pen to draw"<<endl;
    }
};

class Crayon : public Pen{
public:
    Crayon(Color* color){
        this->color=color;
    }

    void draw(){
        cout<<"using "<<color->getColor()<<" crayon to draw"<<endl;
    }
};

int main(){

    Color* color = new Blue();
    Pen* brush = new Brush(color);
    brush->draw();

    Color* color1 = new Red();
    Pen* brush1 = new Brush(color1);
    brush1->draw();

    Pen* crayon = new Crayon(color);
    crayon->draw();


    Pen* crayon1 = new Crayon(color1);
    crayon1->draw();

    return 0;
}

/*
 * error report
 *
 * error : invalid new-expression of abstract class type
 * 出现这个错误原因是new 了一个抽象类出错，说明父类（接口）中有纯虚函数没有实现。
 * 接口里的纯虚函数全部需要实现，这样才能new 子类。纯..
 *
 * error: cannot declare field to be of abstract type
 * 类Pen里的成员类Color color必须声明为Color* color
 *
 */
