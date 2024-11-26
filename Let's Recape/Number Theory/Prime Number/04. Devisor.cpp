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



// Topic : Count devisors by hermonic series (TC -->  n * log(n) )

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