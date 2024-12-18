#include<bits/stdc++.h>
using namespace std ;

const int mx = 2e5+123;
struct Disjoint_set_union
{
    int Parent[mx], Size[mx];

    void Init(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int Find(int v)
    {
        if (v == Parent[v]) return v;
        // Path compression
        return Parent[v] = Find(Parent[v]);
    }

    bool Union(int u, int v)
    {
        int root_u = Find(u);
        int root_v = Find(v);

        if (root_u != root_v)
        {
            if (Size[root_u] < Size[root_v])
            {
                swap(root_u, root_v);
            }
            Parent[root_v] = root_u;
            Size[root_u] += Size[root_v];
            return true;                  // Union performed
        }
        return false; // 'u' and 'v' are already in the same set
    }
} DSU;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ;
    cin>> n >> m ;
    DSU.Init(n);
    while ( m-- )
    {
        int u , v ;
        cin>> u >> v ;
        DSU.Union( u , v );
    }

    int connected_component = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( DSU.Find(i) == i )
        {
            connected_component++;
        }
    }
    cout << connected_component << '\n';


    return 0 ;
}


// Video : https://youtu.be/zEAmQqOpfzM?si=gL3xZUegJmZVxDlI 
Problem : https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/ 