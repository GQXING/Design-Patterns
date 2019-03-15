#include<iostream>
#include<list>
using namespace std;

#ifndef OBJECT_DELETE
#define OBJECT_DELETE(p) { if(p){ delete(p); (p) = NULL;} }
#endif

class Observer{
public:
    virtual void update(string &str) = 0;  //观察者收到通知后做出相应的动作
};

class Subject{
public:
    virtual void attach(Observer *observer) = 0; //注册观察者
    virtual void detach(Observer *observer) = 0; //注销观察者
    virtual void notify(string str) = 0; //通知观察者
};

class Student : public Observer{
public:
    Student(string name){
        this->name = name;
    }
    void update(string &str){       //学生对接受的知识(str)进行理解
        cout << this->name << " understand something like "+str << "." << endl;
    }
//    bool operator==(const Student& student) const{
//        return student.name == this->name;
//    }
private:
    string name;
};

class Teacher : public Subject{
public:
    Teacher(){}
    void attach(Observer *observer){
        s.push_back(observer);
    }
    void detach(Observer *observer)
    {
        s.remove(observer);
    }
    void notify(string str){    //老师讲解str给所有在听的学生
        cout << "teacher begins to teach " << str << endl;
        cout << "*******************************" << endl;
        for(auto it = s.begin(); it != s.end(); it++){
            (*it)->update(str);
        }
    }
private:
    list<Observer*> s;
};

int main(){
    Teacher *teacher = new Teacher();
    Student *s1 = new Student("张三");
    Student *s2 = new Student("李四");
    Student *s3 = new Student("王五");

    teacher->attach(s1);
    teacher->attach(s2);
    teacher->attach(s3);
    teacher->notify("alogrithm");
    cout<<endl;

    //张三开小差了
    teacher->detach(s1);
    teacher->notify("Math");

    OBJECT_DELETE(s1);
    OBJECT_DELETE(s2);
    OBJECT_DELETE(s3);
    OBJECT_DELETE(teacher);
    return 0;
}
