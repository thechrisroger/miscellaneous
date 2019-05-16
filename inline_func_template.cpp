/*
*function template can also be inlined
*/
#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
inline void TypeOf()
{
    cout << typeid(T).name() << endl;
}

int main()
{
    TypeOf<int>();
    TypeOf<bool>();
    TypeOf<char>();
    TypeOf<double>();
}