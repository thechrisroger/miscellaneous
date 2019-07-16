#include<iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int count = 0;
        while(n)
        {
            n = (n-1)&n;
            ++count;
        }
        cout << count <<endl;
    }
}