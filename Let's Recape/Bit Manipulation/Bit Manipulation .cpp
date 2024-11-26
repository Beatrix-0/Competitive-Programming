// Topic 01 : Binary Number System 
//Code :
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x , y ;
    cin>> x >> y ;

    cout << ( x & y ) << '\n';
    cout << ( x | y ) << '\n';
    cout << ( x ^ y ) << '\n';
    cout << ~(x)  << " " << ~(y) << '\n';

    return 0;
}


// Topic 02 : Left shift ( << ) , Right shift ( >> )
//Code :
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x , y ;
    cin>> x >> y ;

    cout << ( x << n ) << '\n'; // Left shift 
    cout << ( x >> n ) << '\n'; // Right shift 

    return 0;
}

//Topic 03 : Checking the last bit is set/on or unset/off and odd or even 
//Code :
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>> n ;
    
    if ( n & 1 ) 
    {
        cout << "The last bit is on" << '\n';
        cout << "The number is odd" << '\n';
    }
    else 
    {
        cout << "The last bit is off " << '\n';
        cout << "The number is even" << '\n';
    }

    return 0;
}

//Topic 04 : Checking the kth bit is set/on or unset/off 
//Code :
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ,  k;
    cin>> n >> k;

    // By left shift
    if ( n & ( 1 << k ))
    {
        cout << "The kth bit is on" << '\n';
    }
    else
    {
        cout << "The kth bit is off" << '\n';
    }

    // By right shift
    if ( (n >> k ) & 1 )
    {
        cout << "The kth bit is on" << '\n';
    }
    else
    {
        cout << "The kth bit is off" << '\n';
    }

    return 0;
}


// Code : When n is greater then 32 bit and less then 64 bit 
#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int main()
{
    LL n = 1e7+123 , k ;
    cin>> k ;

    // By left shift ke LL e convert korte e hobe
    if ( n & ( 1LL << k ))
    {
        cout << "The kth bit is on" << '\n';
    }
    else
    {
        cout << "The kth bit is off" << '\n';
    }

    // By right shift k kicho korte hobe na
    if ( (n >> k ) & 1 )
    {
        cout << "The kth bit is on" << '\n';
    }
    else
    {
        cout << "The kth bit is off" << '\n';
    }

    return 0;
}


//Topic 05 : How we can on or off a bit 
// Code :
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n , k ;
   cin>> n >> k ;

    // Kth bit on korar por
   cout << ( n | ( 1 << k )) << '\n'; 
    // Kth bit of korar por
   cout << ( n & ( (1 << n )-1 - ( 1 << k ) ))  << '\n'; 

    return 0;
}

//Topic 06 : Bit masking 
//Code :
#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int n , k ;
    cin>>n >> k;
    vector < int > v(n);
    for ( int i = 0 ; i< n ; i++)
    {
        cin>> v[i];
    }

    int ans = 0 ;
    for ( int mask = 0 ; mask < ( 1 << n ) ; mask++ ) // all possible subset
    {
        int sum = 0 ;
        for (int i = 0 ; i< n ; i++ )
        {
            if ( (mask >> i )&1)
            {
                sum = sum + v[i];
            }
        }
        if ( sum == k )
        {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}


//Topic 07 : Some builtin function 
//Code :
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    cout << __builtin_popcount(n) << '\n';
    cout << __builtin_ctz(n) << '\n';
    cout << __builtin_clz(n) << '\n';


    return 0;
}


//Topic 08 : Checking if the input is power of 2 
//Code : ( Method -1 )
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int cnt = 0 ;
   for ( int i = 0 ; i< 31 ; i++ )
   {
       if ( n & 1)
       {
           cnt++;
       }
       n = ( n >> 1 );
   }

   if ( cnt == 1 )
   {
       cout << "The input is power of 2" << '\n';
   }
   else
   {
       cout << "The input is not power of 2" << '\n';
   }

    return 0;
}

//Code : ( Method -1 )
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   if ( (n & ( n - 1 )) == 0 )
   {
       cout << "The input is power of 2" << '\n';
   }
   else
   {
       cout << "The input is not power of 2" << '\n';
   }

    return 0;
}


//Topic 09 : X-OR quaries on sub array
//Code :
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ;
    cin>>n;
    int a[n];
    for ( int i = 0 ; i< n ;i++ )
    {
        cin>> a[i];
    }

    int pre[n];
    pre[0] = a[0];

    for ( int i = 1 ; i < n ;i++) // Calculating prefix x-or
    {
        pre[i] = pre[i-1] ^ a[i];
    }

    int q; // query
    cin>>q;
    while(q--)
    {
        int l , r ;
        cin>> l >> r;
        if ( l == 0 )
        {
            cout << pre[r] << '\n';
        }
        else
        {
            cout << (pre[r] ^ pre[l-1]) << '\n';

        }
    }

    return 0;
}

//Topic 10 : find the ( a % 2^n )
//Code :
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a , n ;
    cin >> a >> n;

    cout << ( a & (( 1 << n ) - 1) );

    return 0;
}


//Topic 11 : All pair sum X-OR of an aray 
//Code :
#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0 ;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ 2 * a[i];
    }

    cout << ans << '\n';
    return 0;
}

//Topic 12 : Bitset ( Some builtin function )
//Code :
#include<bits/stdc++.h>
using namespace std;
int main()
{

    bitset<32>bset(5);
    cout << bset << '\n';

    bitset<32>bset(string("101"));
    cout << bset.to_ullong() << '\n';

    bitset<32>bset;
    bset.set();
    cout << bset << '\n';

    bitset<32>bset;
    bset.reset();
    cout << bset << '\n';

    bitset<32>bset(5);
    cout << bset.count() << '\n';

    bitset<32>bset(5);
    cout << bset << '\n';
    bset.flip();
    cout << bset << '\n';

    bitset<32>bset_ind(1);
    cout << bset_ind[0] << " " << bset_ind[1] << '\n';

    return 0;
}






