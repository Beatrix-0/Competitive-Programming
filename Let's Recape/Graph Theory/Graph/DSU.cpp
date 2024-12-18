/// TC = O(n+m*α(n))

#include<bits/stdc++.h>
using namespace std ;

const int mx = 2e5+123;
int Parent[mx];
int Size[mx];

void Make ( int v )
{
    Parent[v] = v ;
    Size[v] = 1 ;
}

int Find( int v )
{
    if ( v == Parent[v] ) return v ;
    // Path compression 
    return Parent[v] = Find(Parent[v]);
}

void Union ( int a, int b )
{
    int root_a = Find(a);
    int root_b = Find(b);
    if ( root_a != root_b )
    {
        // Union by size 
        if ( Size[root_a] < Size[root_b] )
        {
            swap( root_a, root_b );
        }
        Parent[root_b] = root_a ;
        Size[root_a] += Size[root_b];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m ;
    cin>> n >> m ;

    for ( int i = 1 ; i <= n ; i++ )
    {
        Make(i);
    }
    while ( m-- )
    {
        int u, v ;
        cin>> u >> v ;
        Union( u, v );
    }

    int conected_component = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( Find(i) == i )
        {
            conected_component++;
        }
    }

    cout << conected_component << '\n';

    return 0 ;
}
