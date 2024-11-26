#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , mod = 1e9+7;
int dp[N];

int solve ( int n )
{
    if ( n == 0 ) return 1 ;

    if ( dp[n] != -1 ) return dp[n];
    int ans = 0 ;
    for ( int i= 1 ; i = n ; i++ )
    {
      ans = ans + solve( n - i );
      ans = ans % mod ;
    }

   dp[n] = ans;
   return dp[n] ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset ( dp , -1 , sizeof(dp));
    int n ; cin >> n ;
    int ans = solve( n );
    cout << ans << '\n';


    return 0 ;
}
