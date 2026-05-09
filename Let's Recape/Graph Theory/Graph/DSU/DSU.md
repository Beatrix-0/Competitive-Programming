## DSU Code

```cpp

#include<bits/stdc++.h>
using namespace std ;

const int mx = 2e5+123;
struct Disjoint_set_union{
    int Parent[mx], Size[mx];
    void Init(int n){
        for (int i = 0; i <= n; i++){
            Parent[i] = i;
            Size[i] = 1;
        }
    }
    int Find(int v){
        if (v == Parent[v]) return v;
        return Parent[v] = Find(Parent[v]);
    }
    bool Union(int u, int v){
        int root_u = Find(u);
        int root_v = Find(v);
        if (root_u != root_v){
            if (Size[root_u] < Size[root_v]){
                swap(root_u, root_v);
            }
            Parent[root_v] = root_u;
            Size[root_u] += Size[root_v];
            return true;
        }
        return false;
    }
} dsu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ;
    cin>> n >> m ;
    dsu.Init(n);
    while ( m-- ){
        int u , v ;
        cin>> u >> v ;
        dsu.Union( u , v );
    }

    int conCmp = 0 ;
    for ( int i = 1 ; i <= n ; i++ ){
        if ( dsu.Find(i) == i ){
            conCmp++;
        }
    }
    cout << conCmp << '\n';
    return 0 ;
}
```

## Application

1. [Offline Reverse Processing](https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D)
