//Topic : Modular Multiplicative Inverse (log(n))
#include<bits/stdc++.h>
using namespace std ;

#define LL long long int
const int mod = 1e9+7;

int power ( int a , int n , int mod )
{
    if ( n == 1 )
    {
        return a % mod ;
    }
    else
    {
        if ( n % 2 == 0 )
        {
            int x = power( a , n/2 , mod );
            return ( x * 1LL * x ) % mod ;
        }
        else
        {
            int x = power( a , n/2 , mod );
            return ( x * 1LL * x ) % mod * a % mod ;
        }
    }

}

int inverse ( int a , int n )
{
    return ( power ( a , n-2 , n ) );
}

int main()
{
    int a = 5 , n = 7;
    cout << inverse ( a , n );

    return 0;
}