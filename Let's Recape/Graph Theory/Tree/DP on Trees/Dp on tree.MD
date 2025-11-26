# 01. DP on Tree 
DP on Trees (also known as Tree DP) is a dynamic programming technique applied to tree structures. It helps solve problems where the solution for a node depends on the solutions of its children. </br>
## Key idea : 
- Process the tree using DFS (Depth-First Search).
- Compute values bottom-up, using previously computed results from child nodes.
- Store intermediate results in an array (usually dp[node]).
## 5 General Steps in DP on Tree*** 
1. Find out what ( **Observation part** ) info( **DP Values** ) you need to compute for each node.</br>
**Note:** Any info we compute recursively for each node in the tree is essentially our DP state.
2. Root the tree at node 1 
3. Base case : dp[leap] = something ( based on problem )
4. Recurrence equation : 
- $$ dp[u] = \sum_{} dp[v]  $$ 
- $$ dp[u] = 1 + \sum_{} dp[v]  $$ 
- $$ dp[u] = 1 + Totat sum - \sum_{} dp[v]  $$ 
this are the basic recurence relation , which can be vary from problem to problem . Here **u** denote the parent node and **v** denote the child note of that parent.
</br>
5. Last one is implementation 

# 02. How to Implement any DP on Trees
Problem : Subordinates ( CSES )
```
#include<bits/stdc++.h>
using namespace std ;

const int mx = 2e5+123;
vector < int > g[mx];
vector < int > subSize(mx);// the DP values we compute 
bool is_leaf( int u ){
    return ( u != 1 && g[u].size() == 1 );
}

void dfs( int u , int par ){ 
    if (is_leaf(u)){ // Base case
        subSize[u] = 1 ;
        return;
    }

    for ( auto v : g[u]){ // recurence call( its go to leaf first || bottom to top )
        if ( v != par ){
            dfs( v , u );
        }
    }

    for ( auto v : g[u]){ // recurence equation ( can be differ from problem to problem )
        if ( v != par ){
            subSize[u] += subSize[v];
        }
    }
    subSize[u]++; 

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n ; cin>> n ;
    for (int i = 2 ; i <= n ; i++ ){
        int par ;
        cin>> par ;
        g[par].push_back(i) ;
        g[i].push_back(par) ;
    }
    dfs( 1 , -1 );

    for ( int i = 1 ; i <= n ; i++ ){
        cout << subSize[i]-1 << " ";
    }
    
    return 0 ;
}
```
Problem : A. Parsa's Humongous Tree (CF)
```
#include<bits/stdc++.h> // [T_L]
using namespace std ;

#define int long long 
const int mx = 1e5+123;
int n ;
vector <int> g[mx];
vector<pair<int,int>>range;
int dp[mx][2]; // 2 state : dp[node][0]-> L , dp[node][1]-> R

bool isLeaf( int u){
    return ( u != 1 && g[u].size() == 1 );
}

void dfs( int u , int par ){
    // some times it not necessery to use base case 
    //for example in this problem we allready consider
    // all the distance is 0(which is a base case )
    if( isLeaf(u)){ //base case ( 
        dp[u][0] = 0 ; 
        dp[u][1] = 0;
        return ;
    }

    for ( auto v : g[u]){ // go to the bottom ( leaf node )
        if ( v != par ){
            dfs( v , u );
        }
    }

    for ( auto v : g[u]){ // recursive function
        if ( v != par ){
            dp[u][0] += max ( abs(range[u].first - range[v].first)+dp[v][0] , abs(range[u].first - range[v].second)+dp[v][1] );
            dp[u][1] += max ( abs(range[u].second - range[v].first)+dp[v][0] , abs(range[u].second - range[v].second)+dp[v][1] );
        }
        
    }
}

void Resize(){
    range.clear();
    range.resize(n + 1);
    for( int i = 1 ; i <= n ; i++ ){
        g[i].clear();
        dp[i][0] = 0 , dp[i][1] = 0;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ;  cin>> t; 
    while ( t-- ){
        cin>> n ;
        Resize();
        for( int i = 1 ; i <= n ; i++ ){
            int l , r ;
            cin>> l >> r ;
            range[i] = {l , r };
        }
        for ( int i = 0 ; i < n-1 ; i++ ){
            int u , v ;
            cin>> u >> v ;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,-1);
        cout << max ( dp[1][0] , dp[1][1]) << '\n';
    }
    
    return 0 ;
}
```
**FAQ** : </br>
Q. If my DFS function does not return anything when it reaches a leaf node, will it return automatically?</br>
A. Yes, if your DFS function is void, it will return automatically when it reaches a leaf node and has no further recursive calls to make.</br>
Q. What does DP State mean ?</br>
A.  DP state represents a specific subproblem whose result is stored to avoid recomputation.
</br>

Problem : D. Tree Jumps ( CF ) // Iterative approch 
```
#include<bits/stdc++.h> // [UPS]
using namespace std ;

#define int long long 
const int M = 998244353 ; 
const int mx = 3e5+123;
vector < int > g[mx];
vector<int> lev[mx];
int dp[mx];
int sum[mx]; // level sum 

void dfs( int u , int lv = 0 ){
    lev[lv].push_back(u);
    for ( auto v : g[u]){
        dfs(v , lv+1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ;  cin>> t; 
    while ( t-- ){
        int n ; cin>> n;
        for ( int i = 0 ; i <= n ; i++ ){
            g[i].clear();
            lev[i].clear();
            dp[i] = 0 ;
            sum[i] = 0 ;
        } 
        for ( int i = 2 ; i <= n ; i++ ){
            int par ; cin>> par ;
            g[par].push_back(i);
        }

        dfs(1);
        for ( int i = n ; i >= 1 ; i--){
            for ( auto u : lev[i]){
                dp[u] = 1 + sum[i+1];
                for ( auto v : g[u]){
                    dp[u] -= dp[v];
                    dp[u] = (dp[u] % M + M) % M;
                }
                dp[u]%=M;
                sum[i] += dp[u];
                sum[i]%=M;
            }
        }
        cout << (((1+sum[1])%M+M)%M) << '\n';
    }
    
    return 0 ;
}
```

