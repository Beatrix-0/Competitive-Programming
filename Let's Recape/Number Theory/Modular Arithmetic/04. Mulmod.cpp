// Topic : Mulmod 

//Code : when 'a' 'mod' 'n' are larger 
#include<bits/stdc++.h>
using namespace std ;

#define LL long long int
const LL mod = 1e18+123;

LL mulmod ( LL a , LL n , LL mod )
{
    if ( n == 1 )
    {
        return a % mod ;
    }
    else
    {
        if ( n % 2 == 0 )
        {
            LL x = mulmod( a , n/2 , mod );
            return ( x + x ) % mod ;
        }
        else
        {
            LL x = mulmod( a , n/2 , mod );
            return (( x + x ) % mod + a) % mod ;
        }
    }

}

int main()
{
    LL a = 1e16+1 , n = 1e18+1 ;
    cout << mulmod ( a , n , mod );

    return 0;
}

// Code : by __int128 
#include<bits/stdc++.h>
using namespace std ;

#define LL long long int
const LL mod = 1e18+123;

LL mulmod ( LL a , LL n , LL mod )
{
    return __int128( a ) * n % mod ;

}

int main()
{
    LL a = 1e16+1 , n = 1e18+1 ;
    cout << mulmod ( a , n , mod );

    return 0;
}