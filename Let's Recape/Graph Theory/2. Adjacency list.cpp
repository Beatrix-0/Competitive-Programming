#include<bits/stdc++.h> // Space complexity O(n + m)
using namespace std ;

const int N = 105 ;
vector < int > g(N);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // n = number of node || m = number of edges
    int n , m ;
    cin>> n >> m ;
    while ( m-- )
    {
        int u , v ;
        cin>> u >> v;

        // Undirected graph
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for ( auto v : g[2])
    {
        // printing edges of node(2)
        cout << v << ' ';
    }
    cout << '\n';

    // Degree
    for ( int i = 1 ; i <= n ; i++ )
    {
        cout << g[i].size() << ' ';
    }
    cout << '\n';


    return 0 ;
}

/* Input
4 5
1 2
2 4
3 1
1 4
2 3

*/
