// Topic 01 : Binary Exponentiation (Bigmod) //

// Code : Recursive Method  (log(n))
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

int main()
{
    int a = 3 , n = 1000000000;
    cout << power( a , n , mod );

    return 0;
}


// Code : Iterative Method  (log(n)

#include<bits/stdc++.h>
using namespace std ;

#define LL long long int 
const int mod = 1e9+7;

int bin_power ( int a , int n )
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

int main()
{
    int a = 3 , n = 1000000000;
    cout << bin_power( a , n );

    return 0;
}