#include <iostream>

using namespace std;
using ll = long long;

ll quick_pow(ll base, ll exp)
{
    ll res = 1;
    while(exp > 0)
    {
        if(exp & 1) res = res * base;
        base = base * base;
        exp >>= 1;
    }

    return res;
}


int main()
{
    cout << quick_pow(3, 13) << endl;
    return 0;
}