//侯捷oop练习
//测试类的组合和继承关系的构造析构顺序
#include <iostream>
using namespace std;

class A
{
public:
    A(){
        cout << "class A ctor" << endl;
    }
    ~A(){
        cout << "class A dtor" << endl;
    }
};

class B
{
public:
    B(){
        cout << "class B ctor" << endl;
    }
    ~B(){
        cout << "class B dtor" << endl;
    }
};

class C: public B
{
public:
    C(){
        cout << "class C ctor" << endl;
    }
    ~C(){
        cout << "class C dtor" << endl;
    }
    A a;
};

void test(){
    C c;
}

int main()
{
    test();
    return 0;
}
//结果 先父类构造， 再类成员构造， 最后本体构造；析构相反