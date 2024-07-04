#include <bits/stdc++.h> // finding the Fibonacci by using DP
using namespace std;

int fibo ( int n , vector<int>&dp )
{
    if ( n <= 1 ) // ekhane 0 and 1 count hobe
    {
        return n ;
    }
    if ( dp[n] != -1 ) // mane dp te jegola calculate hoyeche ogola r jonno abar recursion colbe na
                         // dp tei jegola calculate korche ogolai return hobe ... tai TC onek kome jay
    {
        return dp[n];
    }

    return dp[n] = fibo( n -1 , dp) + fibo( n - 2 , dp );
}

int main()
{
   int n;
   cin>>n;

   vector< int > dp ( n +1 , -1 );

   int ans = fibo ( n , dp );

   cout << ans << '\n';

    return 0;
}

/*
Video link : https://youtu.be/tyB0ztf0DNY?feature=shared
Topic : DP 1. Introduction to Dynamic Programming | Memoization | Tabulation | Space Optimization
*/