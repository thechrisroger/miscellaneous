#include<iostream>
#include<set>

using namespace std;

int main()
{
    set<int> intset;
    int n,temp;
    cin >> n;
    while(n--)
    {
        cin >> temp;
        intset.emplace(temp);
    }
    auto beg = intset.begin();
    auto theend = intset.end();
    --theend;

    cout << typeid(beg).name() << endl;
    int newdiff,olddiff;
    olddiff = *beg - *(++beg);
    bool feasible = true;
    for( ; beg != theend ; beg)
    {
        newdiff = *beg - *(++beg);
        if(olddiff != newdiff)
        {
            feasible = false;
            cout << olddiff << " != " << newdiff << endl;
        }
    }
    if(feasible)
        cout << "possible" << endl;
    else
        cout << "impossible" << endl;
}