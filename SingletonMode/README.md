# 单例模式

### 概念

​	通过单例模式可以保证系统中，应用该模式的一个类只有一个实例。有时候一些类是属于工具性质的，基本不用存储太多的跟自身有关的数据，在这种情况下，每次都去new一个对象，即增加了开销，也使得代码更加臃肿。其实，我们只需要一个实例对象就可以。如果采用全局或者静态变量的方式，会影响封装性，难以保证别的代码不会对全局变量造成影响。

##### 饿汉模式

​	对象初始化的时候就创建了该对象，由于要进行线程同步，所以在访问量比较大，或者可能访问的线程比较多时，采用饿汉实现，可以实现更好的性能。这是以空间换时间。

##### 懒汉模式

​	对象初始化的时候，声明该对象为空，第一次用到时才去创建对象。在访问量较小时，采用懒汉实现。这是以时间换空间。（本案例采用懒汉模式）

### error report

1. 静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。我们不能把静态成员的初始化放置在类的定义中，但是可以在**类的外部通过使用范围解析运算符 `::`** 来重新声明静态变量从而对它进行初始化。比如：

   ```C++
   class Singleton{
   private:
       Singleton(){}
       Singleton& operator =(const Singleton& ){}
   public:
       static Singleton* getSingleton(){
           ...
       }
   private:
        static Singleton* instance;
        static mutex mutex_;
   };
   
   //初始化
   Singleton* Singleton::instance  = NULL;
   mutex Singleton::mutex_;
   ```

   如果没有初始化，就会出现大量错误，如下：

   ```
   undefined reference to `Singleton::instance'
   undefined reference to `Singleton::mutex_'
   ...
   ```




### Note

```
 if(instance == NULL){
            mutex_.lock();
            instance = new Singleton();
            mutex_.unlock();
	}
```

加锁是为了防止多线程下出现多个实例。