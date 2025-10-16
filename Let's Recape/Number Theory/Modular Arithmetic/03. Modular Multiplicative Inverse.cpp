//Topic : Modular Multiplicative Inverse (log(n))
#include<bits/stdc++.h>
using namespace std ;

#define LL long long int
int bin_power ( int a , int n , int mod)
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

int inverse ( int a , int n ){
    return ( bin_power ( a , n-2 , n ) );
}

int main()
{
    int a = 5 , n = 7;
    cout << inverse ( a , n ); // is this calculating (a⁻¹ % n)

    return 0;
}