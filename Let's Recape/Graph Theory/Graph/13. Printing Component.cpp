#include<bits/stdc++.h>
using namespace std ;

const int mx = 1e5+123;
vector <int> g[mx];
vector <int> comp[mx];
int vis[mx];

void dfs( int node , int com_ind)
{
    comp[com_ind].push_back(node);
    vis[node] = true ;
        for( auto edge : g[node])
        {
            if ( !vis[edge])
            {
                dfs(edge , com_ind);
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ;
    cin>> n >> m ;
    for ( int i = 0 ; i < m ; i++ )
    {
        int u , v ;
        cin>> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i , cnt);
        }
    }

    cout << cnt << '\n';
    for ( int i = 1 ; i <= cnt ; i++ )
    {
        for ( int j = 0 ; j < comp[i].size() ; j++ )
        {
            cout << comp[i][j] << " ";
        }
    }
    cout << '\n';



    return 0 ;
}


// Problem : https://cses.fi/problemset/task/1666