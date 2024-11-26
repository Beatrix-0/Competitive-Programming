//Topic : Large Exponentiation by using Binary Multiplication 

//Code : When 'a' and 'mod' are larger (log^2(n))
#include<bits/stdc++.h>
using namespace std ;

#define LL long long int
const LL mod = 1e18 + 123 ;

LL bin_multiply(LL a, LL n) // zog kore gon korche
{
    LL ans = 0;
    while (n)
    {
        if (n & 1) // bit of naki on check korche
        {
            ans = (ans + a) % mod;
        }

        a = (a + a) % mod;
        n >>= 1; // jei bit niye kaj koreche otake remove kore dicche right shift kore
    }
    return ans;
}

LL bin_power(LL a, LL n)
{
    LL ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = bin_multiply(ans, a);
        }
        a = bin_multiply(a, a);
        n >>= 1;
    }
    return ans;
}

int main()
{
    LL a = 1e18, n = 1000000000;
    cout << bin_power(a, n);

    return 0;
}