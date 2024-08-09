#include<bits/stdc++.h> // Complexity O(N*N)
using namespace std ;

const int N = 1e5;
vector < int > g(N);
bool vis[N];
int indeg[N];

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
        indeg[v]++;
        g[u].push_back(v);
    }

    bool ok = true ;
    vector < int >ans ;
    while ( ans.size() < n )
    {
        int cur = 0 ;
        for ( int i = 1 ; i <= n ; i++ )
        {
            if ( !vis[i] && indeg[i] == 0 )
            {
                cur = i ;
                break ;
            }
        }
        if ( cur == 0 )
        {
            cout << "IMPOSSIBLE" << '\n'; // Dedect a cycle in graph
            return 0 ;
        }
        vis[cur] = true ;
        ans.push_back(cur);
        for ( auto v : g[cur])
        {
            intdeg[v]--;
        }

        for ( auto it : ans )
        {
            cout << it << ' ';
        }
        cout << '\n';
    }


    return 0 ;
}

---------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h> // Complexity O(V+E) Using DFS
using namespace std ;

const int N = 1e5;
vector < int > g(N);
bool vis[N];
int indeg[N];

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
        indeg[v]++;
        g[u].push_back(v);
    }
    vector < int > z ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( indeg[i] == 0 )
        {
            z.push_back(i);
            vis[i] = true ;
        }
    }
    bool ok = true ;
    vector < int >ans ;
    while ( ans.size() < n )
    {
        if ( z.empty())
        {
            cout << "IMPOSSIBLE" << '\n';
            return 0 ;
        }
        int cur = z.back();
        z.pop_back();
        ans.push_back(cur);
        for ( auto v : g[cur])
        {
            indeg[v]--;
            if ( !vis[v] && deg[v] == 0 )
            {
                z.push_back(v);
                vis[v] = true ;
            }
        }
        for ( auto it : ans )
        {
            cout << it << " ";
        }
        cout << '\n';
    }


    return 0 ;
}

