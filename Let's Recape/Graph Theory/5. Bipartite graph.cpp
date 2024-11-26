#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 ;
vector< int > g(N);
bool vis[N];
bool ok ;
int col[N];

void dfs( int u )
{
    vis[u] = true ;
    for ( auto v : g[u] )
    {
        if ( !vis[v] )
        {
           col[v] = col[u] ^ 1 ;
           dfs(v);
        }
        else
        {
            if ( col[v] == col[u] )
            {
                ok = false ;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ;
    cin>> n >> m ;
    while ( m-- )
    {
        int u , v ;
        cin>> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ok = true ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( !vis[i] )
        {
           dfs(i);
        }
    }

    if (ok)
    {
        cout << "The graph is Bipartile" << '\n';
    }
    else
    {
        cout << "The graph is not Bipartile" << '\n';
    }


    return 0 ;
}

// Problem : https://cses.fi/problemset/task/1668/