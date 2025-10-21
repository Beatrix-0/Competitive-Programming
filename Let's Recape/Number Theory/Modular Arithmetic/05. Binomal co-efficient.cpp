// Topic : Binomal co-efficient using mudolar arithmatic ( nCr ) 
//Code :
#include<bits/stdc++.h> 
using namespace std;

#define LL long long int
const int mod = 1e9+7;

int fact(int x)
{
    int ans = 1;
    for(int i = 2; i <= x; i++)
    {
        ans = (ans * 1LL * i) % mod;
    }
    return ans ;
}

int inverse ( int a , int n)
{
    int ans = 1 ;
    while ( n )
    {
        if ( n & 1)
        {
            ans = ( ans * 1LL * a ) % mod ;
        }
        a = ( a *1LL * a )% mod ;
        n >>= 1 ;
    }
    return ans ;
}

signed main()
{
    int n, r, a, b, c, ans, opr1, opr2;
    cin >> n >> r;      
    a = fact(n);
    b = fact(r);
    c = fact(n - r);
    ans =  a;
    opr1 = inverse(b, mod - 2);
    opr2 = inverse(c, mod - 2);
    ans = (ans * 1LL * opr1) % mod;
    ans = (ans * 1LL * opr2) % mod;
    cout << "nCr : " << ans << endl;

    return 0;
}


Problem :
1. https://codeforces.com/contest/1922/problem/B