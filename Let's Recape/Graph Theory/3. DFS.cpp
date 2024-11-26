#include<bits/stdc++.h>
using namespace std ;

const int N = 105 ;
vector < int > g(N);
bool vis[N];

void dfs ( int u )
{
    vis[u] = true ;
    for ( auto v : g[u])
    {
        if ( !vis[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ; cin>> n >> m;
    while ( m-- )
    {
        int u , v ;
        cin>> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    /*dfs(1);
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( !vis[i] )
        {
            cout << "Not Connected! " << '\n';
            break ;
        }
    }*/

    int ans = 0;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( !vis[i] )
        {
            ans++;
            dfs(i);
        }
    }

    cout << "There are " << ans << " connected component " << '\n';

    return 0 ;
}
/* Input
4 5
1 2
2 3
3 1
4 5
5 6
*/
