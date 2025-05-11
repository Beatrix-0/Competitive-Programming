// Topic : Primality Check 
// Code :
#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin>>n ;

    bool isPrime = true ;

    if ( n == 0 || n == 1 )
    {
        isPrime = false ;
    }

    for ( int i = 2 ; i * i <= n ; i++ )
    {
        if ( n % i == 0 )
        {
            isPrime = false ;
            break ;
        }
    }

    if ( isPrime )
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }

    return 0;
}

1. https://codeforces.com/problemset/problem/230/B