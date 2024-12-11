#include<bits/stdc++.h>
using namespace std ;

const int mx = 2e5+123;
vector < int >g[mx];
bool vis[mx];
int st_cycle = -1, ed_cycle = -1 ;
int par[mx]; // min node start form 1 so initial all par to 0 is valid ... if node start form 0 then we have to initial all -1

bool dfs ( int u, int parent )
{
    vis[u] = true ;
    for ( auto v : g[u])
    {
        if ( v == parent )
        {
            continue ;
        }
        if ( vis[v])
        {
            st_cycle = v, ed_cycle = u ;
            return true ;
        }
        par[v] = u ;
        if ( dfs(v, u ) == true )
        {
            return true ;
        }
    }
    return false ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m ;
    cin>> n >> m ;
    while ( m-- )
    {
        int u, v ;
        cin>> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( !vis[i])
        {
            if ( dfs(i, 0 ) == true )
            {
                break ;
            }
        }
    }

    if ( st_cycle == -1 )
    {
        cout << "IMPOSSIBLE" << '\n'; // Acyclic
    }
    else
    {
        vector < int > cycle;
        cycle.push_back(st_cycle);
        for ( int u = ed_cycle ; u != st_cycle ; u = par[u])
        {
            cycle.push_back(u);
        }
        cycle.push_back(st_cycle);
        cout << cycle.size() << '\n';
        for ( auto it : cycle )
        {
            cout << it << " ";
        }
        cout << '\n';
    }

    return 0 ;
}

/*Input:

5 6
1 3
1 2
5 3
1 5
2 4
4 5*/
//video : https://youtu.be/zQ3zgFypzX4?si=9YaMvRgayaxu04lp