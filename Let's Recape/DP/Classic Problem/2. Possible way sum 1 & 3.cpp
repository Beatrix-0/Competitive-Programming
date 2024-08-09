#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , mod = 1e9+7;
int dp[N];

int solve ( int n )
{
    if ( n == 1 ) return 1 ;
    if ( n == 2 ) return 1 ;
    if ( n == 3 ) return 2 ;

    if ( dp[n] != -1 ) return dp[n];

    dp[n] = (solve( n -1 ) + solve( n-3)) % mod; // way
    return dp[n] ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset ( dp, -1, sizeof(dp));
    int n ;
    cin>> n ;
    int ans = solve( n );
    cout << ans << '\n';

    return 0 ;
}
