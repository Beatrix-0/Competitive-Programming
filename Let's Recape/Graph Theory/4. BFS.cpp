#include<bits/stdc++.h>  // Complexity O(V + E)
using namespace std ;

const int N = 1e5 ;
vector< int > g[N];
bool vis[N];
int par[N] , dis[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ; cin>> n >> m ;
    while ( m-- )
    {
        int u , v ;
        cin>> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int > q;
    q.push(1); vis[1] = true ; dis[1] = 0 ;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for ( auto v : g[u])
        {
            if ( !vis[v])
            {
                q.push(v);
                vis[v] = true ;
                par[v] = u ;
                dis[v] = dis[u]+1;
            }
        }
    }

    for ( int i = 1 ; i <= n ; i++ )
    {
        cout << dis[i] << " ";
    }
    cout << '\n';

    int v = 4 ;
    while ( v!= 1 )
    {
        cout << v << ' ' ;
        v = par[v];
    }
    cout << 1 << '\n';

    return 0 ;
}
