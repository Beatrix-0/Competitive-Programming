#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5;
int n , W , w[N] , v[N] , dp[N][100005];

int rec( int i , int weight )
{
    if ( i == n + 1 ) return 0 ;
    if ( dp[i][weight] != -1 ) return dp[i][weight] ;
    int ans = rec( i + 1 , weight ); // not taken
    if ( weight + w[i] <= W )
    {
        ans = max ( ans , rec( i + 1 , weight+w[i] )+v[i] ); // taken
    }
    return dp[i][weight] = ans ;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n >> W;
    for ( int i = 1 ; i <= n  ; i++ )
    {
        cin>> w[i] >> v[i];
    }
    memset ( dp , -1 , sizeof(dp));
    cout <<  rec( 1 , 0 ) << '\n';

    return 0 ;
}
