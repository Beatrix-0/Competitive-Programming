// Topic : Binomal co-efficient using mudolar arithmatic ( nCr ) 
//Code :
#include<bits/stdc++.h> 
using namespace std;
 
#define LL long long int
const int mod = 1e9+7;
const int mx = 1e6;
int f[mx];
 
void pre_fact()
{
    f[0] = 1 ;
    for ( int i = 1 ; i <= mx ; i++ ){
        f[i] = (f[i - 1] * 1LL * i) % mod;
    }
}
 
int inverse ( int a , int n)
{
    int ans = 1 ;
    while ( n )
    {
        if ( n & 1){
            ans = ( ans * 1LL * a ) % mod ;
        }
        a = ( a *1LL * a )% mod ;
        n >>= 1 ;
    }
    return ans ;
}
 
signed main()
{
    pre_fact();
    int t ; cin >> t ;
    while ( t-- ){
        int n, r, a, b, c, ans, opr1, opr2;
        cin >> n >> r;      
        a = f[n];
        b = f[r];
        c = f[n-r];
        ans =  a;
        opr1 = inverse(b, mod - 2);
        opr2 = inverse(c, mod - 2);
        ans = (ans * 1LL * opr1) % mod;
        ans = (ans * 1LL * opr2) % mod;
        cout << ans << '\n';
    }
    return 0;
}