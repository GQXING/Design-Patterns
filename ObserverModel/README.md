# 观察者模式

### 定义

​	  观察者模式：定义对象间的一种一对多的依赖关系，当一个对象的状态发生改变时，所有依赖于它的对象都得到通知并被自动更新。它还有两个别名，依赖(Dependents)，发布-订阅(Publish-Subsrcibe)。

### 案例

​	就以学生上课为案例，在上课的过程中，老师相当于主题，学生相当于观察者。老师上课向学生讲解知识的过程就是调用"Notify()"通知观察者（学生），学生继而对收到的知识点进行理解吸收。具体过程如cpp程序。





### note

1. ` #ifndef (if not define) `是一种宏定义判断，作用是防止多重定义。

2. 使用虚函数的时候，其继承类中函数的参数必须和虚函数一样，如：

   ```C++
   class Subject{
   public:
       virtual void attach(Observer *observer) = 0; //注册观察者
       virtual void detach(Observer *observer) = 0; //注销观察者
       virtual void notify(string str) = 0; //通知观察者
   };
   ```

   继承类：

   ```C++
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
           ...
       }
   private:
       list<Observer*> s;
   };
   ```

3. 抽象类是指含有纯虚函数的类(至少有一个纯虚函数)，该类不能创建对象(抽象类不能实例化)，但是可以声明指针和引用，用于基础类的接口声明和运行时的多态。**所以在上例代码中，虚函数和实现类的成员函数的参数都是指针类型**

4. **接口是一个概念。它在C++中用抽象类来实现**，在C#和Java中用interface来实现。