// Implementinng using DFS 
#include<bits/stdc++.h>
using namespace std ;

const int mx = 1e5;
vector<int>g[mx];
int dis[mx]; // depth

void dfs( int node , int par = -1 )
{
    for ( auto child : g[node] )
    {
        if ( child == par ) continue ;
        dis[child] = dis[node] + 1 ;
        dfs(child, node);
    }
}

void clr (int n )
{
    for ( int i = 0 ; i < n ; i++ )
    {
        dis[i] = 0 ;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin>> n ;
    for ( int i = 0 ; i < n-1 ; i++ )
    {
        int u , v ;
        cin>> u >> v ;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    int mx = -1 , first_node ;
    for ( int i = 0 ; i < n ; i++ )
    {
        if ( mx < dis[i])
        {
            mx = dis[i];
            first_node = i;
        }
    }

    clr(n);

    dfs(first_node);
    int mx_depth = -1 ;
    for ( int i = 0 ; i < n ; i++ )
    {
        if ( dis[i] > mx_depth )
        {
            mx_depth = dis[i];
        }
    }
    cout << mx_depth << '\n';

    return 0 ;
}


// Implementing using BFS
#include<bits/stdc++.h>
using namespace std ;
const int mx = 1e5;
vector<int>g[mx];
int dis[mx]; // depth 
int vis[mx];

void bfs( int node )
{
    queue<int>q ;
    q.push(node);
    vis[node] = 1 ;
    while( !q.empty())
    {
        int top = q.front();
        q.pop();
        for ( int i = 0 ; i < g[top].size() ; i++ )
        {
           int edg = g[top][i]; 
           if ( !vis[edg])
           {
               dis[edg] = dis[top] + 1 ;
               vis[edg] = 1 ;
               q.push(edg);
           }
        }
    }
}

void clr( int n )
{
    for ( int i = 0 ; i < n ; i++ )
    {
       dis[i] = 0 ; 
       vis[i] = 0 ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin>> n ;
    for( int i = 0 ; i < n-1 ; i++ )
    {
       int u , v ; 
       cin>> u >> v ;
       
       g[u].push_back(v);
       g[v].push_back(u);
    }
    
    bfs(1);
    
    int mx = -1 , first_node ;
    for ( int i = 0 ; i < n ; i++ )
    {
        if (  mx < dis[i])
        {
            mx = dis[i];
            first_node = i;
        }
    }
    
    clr(n);
    
    bfs(first_node);
    
    int mx_depth = -1 ;
    for ( int i = 0 ; i < n ; i++ )
    {
        if ( mx_depth < dis[i])
        {
            mx_depth = dis[i];
        }
    }
    cout << mx_depth << '\n';
    
    
    return 0 ;
}


// Taste case : 
13
1 2
1 3
1 13 
2 5 
5 6 
5 7 
5 8 
8 12
3 4 
4 9
4 10
10 11

//Problem : https://lightoj.com/problem/farthest-nodes-in-a-tree