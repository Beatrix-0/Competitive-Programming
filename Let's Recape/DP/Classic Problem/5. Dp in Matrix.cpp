#include<bits/stdc++.h>
using namespace std ;

const int N = 100 ;
int n , m , a[N][N] , dp[N][N] , inf = 1e9;

int min_cost ( int i , int j )
{
    if ( i > n || j > m ) return inf ;
    if ( i == n && j == m  ) return a[i][j];
    if ( dp[i][j] != -1 ) return dp[i][j] ;
    int ans = a[i][j] + min (min_cost( i , j + 1 ) , min_cost( i+1 , j));
    return dp[i][j] = ans ;

}

void path( int i , int j )
{
    cout << a[i][j] << " ";
    if ( i == n && j == m ) return ;
    int right = min_cost( i , j + 1 );
    int left = min_cost( i+1 , j );

    if ( right <= left )
    {
        min_cost( i , j + 1 );
    }
    else
    {
        min_cost( i+1 , j );
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n >> m ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= m ; j++ )
        {
            cin>> a[i][j];
        }
    }
    memset ( dp , -1 , sizeof(dp));
    cout << min_cost( 1 , 1 ) << '\n';
     path( 1 , 1 ) ;

    return 0 ;
}
