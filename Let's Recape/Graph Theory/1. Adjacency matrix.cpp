#include<bits/stdc++.h> // Space complexity O(N*N)
using namespace std ;

const int N = 105 ;
int g[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ;
    cin>> n >> m ;
    while ( m-- )
    {
        int u , v ;
        cin>> u >>v ;

        g[u][v] = 1 ;
        g[v][u] = 1 ;
    }

    // Check if the vertex is connected or not
    int x , y ;
    cin>> x >> y ;

    if ( g[x][y] )
    {
        cout << "The vertex are connected " << '\n';
    }
    else
    {
        cout << "The vertex are disconnected " << '\n';
    }

    return 0 ;
}
