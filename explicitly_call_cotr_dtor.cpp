/*
This file is a test for:
explicitly calls constructor to create temporary object

explictly call constructor for object 

implictly calls destructor for (temporary) object
*/
#include <iostream>
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Constructor is executed\n";
    }
    ~Test()
    {
        cout << "Destructor is executed\n";
    }
    void show()
    {
        cout << "call ctor explicitly and destructor implicitly for temporary object\n\n";
        Test();
        cout << "explicitly call destructor\n" << endl;
        //this->Test::~Test();
    }
};

int main()
{
    Test t;
    t.show();
    t.~Test();
    cout << "call destructor implicitly\n\n";

}
