/*
Programing test of Alibaba interview
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    set<int, greater<int>> randset;
    for (int i = 0; i < 100; ++i)
        randset.emplace(rand() % 1000);
    for (auto it:randset)
        cout << it << endl;
}