// Topic : Euler's Totient function / Phi function ( for find how many co-prime in n )
//Code :
#include<bits/stdc++.h>
using namespace std;

void phi ( int n )
{
    int ans = n ;
    int cnt = 0 ;
    for ( int i = 2 ; i * i <= n ; i++ )
    {
        if ( n % i == 0 )
        {
            while ( n % i == 0 )
            {
                cnt++;
                n = n/i;
            }
            // formula of phi function
            ans = ans * ( i - 1 );
            ans = ans / i ;
        }
    }

    if ( n > 1 )
    {
        ans = ans * ( n - 1 );
        ans = ans / n ;
    }

    cout << "Number of devisors : " << cnt << '\n';
    cout << ans << '\n';

}

int main()
{
    int n ;
    cin>> n;
    phi(n);

    return 0;
}

1. https://www.hackerrank.com/challenges/primitive-problem/problem?isFullScreen=true