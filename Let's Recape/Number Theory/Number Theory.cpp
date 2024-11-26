// Topic 01 : Binary Exponentiation (Bigmod) //

// Code : Recursive Method  ( TC --> log(n))
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


// Code : Iterative Method  ( TC --> log(n))
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
        n >> = 1 ;
    }
    return ans ;
}

int main()
{
    int a = 3 , n = 1000000000;
    cout << bin_power( a , n );

    return 0;
}

-----------------------------------------------------------------------------------------------------------------------------------------------

//Topic 02 : Large Exponentiation by using Binary Multiplication 

//Code : When 'a' and 'mod' are larger ( TC --> log^2(n))
#include<bits/stdc++.h>
using namespace std ;

#define LL long long int
const LL mod = 1e18 + 123 ;

LL bin_multiply(LL a, LL n) // zog kore gon korche
{
    LL ans = 0;
    while (n)
    {
        if (n & 1) // bit of naki on check korche
        {
            ans = (ans + a) % mod;
        }

        a = (a + a) % mod;
        n >>= 1; // jei bit niye kaj koreche otake remove kore dicche right shift kore
    }
    return ans;
}

LL bin_power(LL a, LL n)
{
    LL ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = bin_multiply(ans, a);
        }
        a = bin_multiply(a, a);
        n >>= 1;
    }
    return ans;
}

int main()
{
    LL a = 1e18, n = 1000000000;
    cout << bin_power(a, n);

    return 0;
}

-----------------------------------------------------------------------------------------------------------------------------------------------

//Topic 03 : Modular Multiplicative Inverse ( TC --> log(n) )
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

-----------------------------------------------------------------------------------------------------------------------------------------------

// Topic 04 : Mulmod 

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

-----------------------------------------------------------------------------------------------------------------------------------------------

// Topic 05 : Primality Check 
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

-----------------------------------------------------------------------------------------------------------------------------------------------

// Topic 06 : Sieve of Eratosthenes [ Generating prime numbers ]

// Code ( Genarel ) ( TC -->  nlog (logn) )
#include <bits/stdc++.h> 
using namespace std;

const int mx = 1e7+123;
int is_prime[mx];
void sieve ( int n )
{
    for ( int i = 1 ; i*i <= n ; i++)
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

-----------------------------------------------------------------------------------------------------------------------------------------------

//Topic 07 : Prime Factorization (TC -->  sqrt(n) )
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

// Code (  Prime Factorization by Sieve ) (TC -->  log(n) )
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

-----------------------------------------------------------------------------------------------------------------------------------------------

//Topic 08 : Number of devisor ( TC -->  sqrt(n) )
//Code :
#include <bits/stdc++.h>
using namespace std ;

vector<int> v; // devisors

void devisor(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int x = i;
            int y = n / i;

            v.push_back(x);
            if (x != y) v.push_back(y);
        }
    }
}

int main()
{
    int n ;
    cin>> n ;
    devisor ( n );

    sort(v.begin(),v.end());
    cout << "Number of devisors : " << v.size() << '\n';
    int sum = 0 ;
    for ( auto it : v )
    {
        sum = sum + it ;
    }
    cout << "Sum of devisors : " << sum << '\n';

    return 0 ;
}


// Code :  NOD & SOD  by using sieve  ( TC -->  log(n) )
// Range : ( 1 - 1e8 )

#include <bits/stdc++.h>
using namespace std;

vector<int> a(10000001, -1); // assume all numbers are prime (-1)

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

    map<int, int> mp;
    vector<int> factors = primeFactors(n);

    for (int i = 0; i < factors.size(); i++)
    {
        mp[factors[i]]++;
    }

    int SOD = 1 , NOD = 1 ;
    for (auto it : mp)
    {
         NOD = NOD * ( it.second + 1 );

        int p = it.first; // prime factor
        int a = it.second; // power of the prime factor

        // Calculate the sum of divisors for prime factor p^a
        int sum = 0;
        int power = 1;
        for (int i = 0; i <= a; i++)
        {
            sum = sum +  power;
            power = power * p;
        }

        SOD = SOD * sum;
    }

    cout << "Sum of devisor " << SOD << '\n';
    cout << "Number of devisor " << NOD << '\n';

    return 0;
}



//Practice Problem :
1. https://codeforces.com/problemset/problem/1925/B
2. https://codeforces.com/contest/762/problem/A
3. https://codeforces.com/problemset/problem/1203/C

-----------------------------------------------------------------------------------------------------------------------------------------------

// Topic 09 : Count devisors by hermonic series (TC -->  n * log(n) )
//Code :
#include<bits/stdc++.h> 
using namespace std;

const int mx = 1e7+123;
int cnt[mx];

int main()
{
    int n;
    cin>>n;

    for ( int i = 1 ; i <= n ; i++)
    {
        for ( int j = i ; j <=n ; j = j+i) 
        {
            cnt[j]++; // Counting the devisor's
        }
    }

    for ( int i = 1 ; i <= n ; i++)
    {
        cout << "Number : "<< i << " --> " << cnt[i] << '\n'; 
    }
    
    return 0;
}

-----------------------------------------------------------------------------------------------------------------------------------------------

// Topic 10 : Binomal co-efficient using mudolar arithmatic ( nCr ) 
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

int inverse(int a, int n )
{
    if (n == 0)
    {
        return 1 ;
    }
    else
    {
        if (n % 2 == 0)
        {
            int ans = inverse(a, n / 2 );
            ans = (ans * 1LL * ans) % mod;
            return ans;
        }
        else
        {
            int ans = inverse(a, n / 2 );
            ans = (ans * 1LL * ans) % mod;
            ans = (ans * 1LL * a) % mod;
            return ans;
        }
    }
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

-----------------------------------------------------------------------------------------------------------------------------------------------

// Topic 11 : Euclid Algorithm ( GCD )
//Code :
#include<bits/stdc++.h> // Calculate GCD --> Euclid Algorithm
using namespace std;

int gcd( int a, int b )
{
    if ( b == 0 )
    {
        return a ;
    }
    else
    {
        return gcd ( b, a%b );
    }
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int a,b;
    cin>>a>>b;

    // Printing GCD
    int ans_gcd = gcd(a,b);
    cout << "GCD : "<<  ans_gcd << '\n';

    // Printing LCM
    int ans_lcm =  ( a , b ) ;
    cout << "LCM : "<<  ans_lcm << '\n';


    return 0;
}

1. https://www.hackerrank.com/challenges/sherlock-and-gcd/problem?isFullScreen=true

-----------------------------------------------------------------------------------------------------------------------------------------------

// Topic 12 : Euler's Totient function / Phi function ( for find the co-prime )
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













