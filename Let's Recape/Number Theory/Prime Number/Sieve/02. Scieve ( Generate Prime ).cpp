// Code ( Genarel ) ( TC -->  nlog (logn) )
#include <bits/stdc++.h> 
using namespace std;

const int mx = 1e7+123;
int is_prime[mx];
void sieve ( int n )
{
    for ( int i = 1 ; i <= n ; i++)
    {
        is_prime[i] = 1 ;
    }
    is_prime[0] = is_prime[1] = 0 ;

    for ( int i = 2 ; i*i <= n ; i++ )
    {
        if (is_prime[i])
        {
            for ( int j = i*i ; j <= n ; j = j + i)
            {
                is_prime[j] = 0 ;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            cout << i << " " << '\n';
        }
    }

}

int main()
{
    int n;
    cin>>n ;

    sieve(n);

    return 0;
}

// Code ( Linear scieve ) ( TC -->  O(n) )
#include<bits/stdc++.h>
using namespace std ;

const int mx = 1e7+123;
vector<int> v (mx + 1);
vector<int> prime ;

int main()
{
    for (int i = 2; i <= mx; i++ )
    {
        if (v[i] == 0)
        {
            v[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= mx; j++)
        {
            v[i * prime[j]] = prime[j];
            if (prime[j] == v[i])
            {
                break;
            }
        }
    }

    for ( auto it : prime )
    {
        cout << it << " ";
    }
    cout << '\n';

    return 0 ;
}

//Code ( Tc -> almost O(n))

#include<bits/stdc++.h>
using namespace std ;

const int mx = 1e7+9 ;
bitset <mx> prime ;
vector< int > ans ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for ( int i = 1 ; i < mx ; i++ )
    {
        prime[i] = true ;
    }

    for ( int  i = 4 ; i < mx ; i+=2 )
    {
        prime[i] = false ;
    }

    for( int i = 3 ; i < mx ; i+=2 )
    {
        if ( prime[i])
        {
          for( int j = 2*i ; j < mx ; j += i)
          {
              prime[j] = false ;
          }
        }
    }

    for ( int i = 2 ; i < mx ; i++ )
    {
        if ( prime[i])
        {
            ans.push_back(i);
        }
    }

    for ( auto it : ans )
    {
        cout << it << " ";
    }
    cout << '\n';

    return 0 ;
}



// Code ( by boolean )
#include <bits/stdc++.h>
using namespace std ;

const int mx = 1e7+123; 

bool is_prime[mx];
vector<int> prime;

void primeGen ( int n )
{
    n = n + 100;

    for ( int i = 3; i <= n; i = i + 2 )
    {
        is_prime[i] = 1;
    }

    int sq = sqrt ( n );
    for ( int i = 3; i <= sq; i += 2 )
    {
        if ( is_prime[i] == 1 )
        {
            for ( int j = i*i; j <= n; j += ( i + i ) )
            {
                is_prime[j] = 0;
            }
        }
    }

    is_prime[2] = 1;
    prime.push_back(2);

    for ( int i = 3; i <= n; i += 2 )
    {
        if ( is_prime[i] == 1 )
        {
            prime.push_back ( i );
        }
    }

    for ( auto it : prime )
    {
        cout << it << " ";
    }
}

int main()
{
    int n ;
    cin>>n ;
    primeGen(n);
    return 0 ;
}

// Code ( by bitset )
#include <bits/stdc++.h>
using namespace std ;

const int MX = 1e7+123;
bitset<MX> is_prime;
vector<int> prime;

void primeGen ( int n )
{
    n = n + 100;
    for ( int i = 3; i <= n; i += 2 )
    {
        is_prime[i] = 1;
    }

    int sq = sqrt ( n );
    for ( int i = 3; i <= sq; i += 2 )
    {
        if ( is_prime[i] == 1 )
        {
            for ( int j = i*i; j <= n; j += ( i + i ) )
            {
                is_prime[j] = 0;
            }
        }
    }

    is_prime[2] = 1;
    prime.push_back (2);

    for ( int i = 3; i <= n; i += 2 )
    {
        if ( is_prime[i] == 1 )
        {
            prime.push_back ( i );
        }
    }

    for ( auto it : prime )
    {
        cout << it << " ";
    }
}

int main()
{
    int n ;
    cin>>n ;
    primeGen(n);

    return 0 ;
}

1. https://toph.co/p/n-th-prime [ linear scieve ]