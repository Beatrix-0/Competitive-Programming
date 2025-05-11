//Topic 07 : Prime Factorization (sqrt(n) )
#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int n ;
    cin>>n ;
    vector < int > prime_factor ;

    for ( int i = 2 ; i * i <= n ; i++ )
    {
        while ( n%i == 0 )
        {
            prime_factor.push_back(i);
            n = n/i; // i diye jotogola vag jay ogola bade bakigola count hobe next t++ e 
        }
    }
    if ( n > 1 )//last prime number
    {
        prime_factor.push_back(n);
    }

    for ( auto it : prime_factor )
    {
        cout << it << " ";
    }

    return 0 ;
}

// Code (  Prime Factorization by Sieve ) (log(n) )
// Range ( 1 - 1e8 )
#include <bits/stdc++.h>
using namespace std;

vector<int> a(10000001, -1); // assume all number are prime (-1)

void sieve()
{
    int maxN = 10000000;
    for (int i = 2; i <= maxN; i++)
    {
        if (a[i] == -1)
        {
            for (int j = i; j <= maxN; j += i)
            {
                if (a[j] == -1)
                {
                    a[j] = i;
                }
            }
        }
    }
}

vector<int> primeFactors(int n)
{
    vector<int> factors;
    while (n != 1)
    {
        factors.push_back(a[n]);
        n /= a[n];
    }
    return factors;
}

int main()
{
    sieve();

    int n; cin >> n;

    vector<int> factors = primeFactors(n);

    for (int it : factors)
    {
        cout << it << " ";
    }
    cout << '\n';

    return 0;
}

1. https://youtu.be/5eUY1VxvCAs?feature=shared

// Code ( Smallest Prime Factor by Sieve ) (TC -->  log(n) )
// Range ( 1 - 1e8 )

#include <bits/stdc++.h>
using namespace std;

int a[10000001]; 

void sieve()
{
    int maxN = 10000000;
    for (int i = 1; i <= maxN; i++)
    {
        a[i] = -1;
    }

    for (int i = 2; i <= maxN; i++)
    {
        if (a[i] == -1)
        {
            for (int j = i; j <= maxN; j = j + i)
            {
                if (a[j] == -1)
                {
                    a[j] = i;
                }
            }
        }
    }
}

int main()
{
    sieve();

    int n; cin >> n;

    cout << "Smallest prime factor of " << n << " is: " << a[n] << '\n' ;

    return 0;
}


1. https://www.hackerrank.com/challenges/identify-smith-numbers/problem?isFullScreen=true