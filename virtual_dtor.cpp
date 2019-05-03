/*
virtual destructor of class hierachy
*/

#include<iostream>
#include <memory>
using namespace std;
class Base{
public:
    Base(){};
     virtual ~Base()
    {
        cout << "destructor of base class executed\n\n";
    }
};

class D1:public Base{
public:
    D1(){}
    ~D1()
    {
        cout << "destructor of D1 class executed\n";
    }
};

class D2:public D1{
public:
    D2(){}
    ~D2()
    {
        cout << "destructor of class D2 executed\n";
    }
};

int main()
{
    unique_ptr<Base> uc1(new Base);
    unique_ptr<Base> uc2(new D1);
    unique_ptr<Base> uc3(new D2);

    Base *c1 = new Base;
    Base *c2 = new D1;
    Base *c3 = new D2;
    cout << "normal pointer:\n";
    delete c1;
    delete c2;
    delete c3;

    cout << "unique_ptr:\n";
}