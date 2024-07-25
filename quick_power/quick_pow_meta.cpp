#include <iostream>

using namespace std;
using ll = long long;

template<ll A, ll N, bool isEven=(N%2 == 0)>
struct quick_pow_meta;

template<ll A, ll N>
struct quick_pow_meta<A, N, true>{
    static constexpr ll value = quick_pow_meta<A, N/2>::value * quick_pow_meta<A, N/2>::value;
};

template<ll A, ll N>
struct quick_pow_meta<A, N, false>{
    static constexpr ll value = A * quick_pow_meta<A, N/2>::value * quick_pow_meta<A, N/2>::value;
};

template<ll A>
struct quick_pow_meta<A, 0, true>{
    static constexpr ll value = 1;
};


int main()
{
    cout << quick_pow_meta<3, 13>::value << endl;
    return 0;
}