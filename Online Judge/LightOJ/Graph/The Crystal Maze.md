### **Crystal Maze - Explanation & Solution Approach**

The problem presents a **grid-based traversal** challenge where we must compute the number of crystals ('C') that can be collected from different starting positions in a **maze with walls ('#')**. The constraints make it necessary to use **efficient traversal techniques** to solve the problem optimally.

**Understanding the Problem Statement**
---------------------------------------

1.  The maze is given as an **M x N** grid.
    
2.  You can move **only in four directions**: **left, right, up, or down**.
    
3.  Walls ('#') are **impassable**.
    
4.  Crystals ('C') need to be **collected**.
    
5.  Given **Q queries**, for each query (landing position (xi, yi)), determine **how many crystals can be collected** starting from (xi, yi).
    

**Key Observations**
--------------------

1.  **Connected Component Concept**
    
    *   If two positions in the maze can be reached from one another, they belong to the **same connected component**.
        
    *   All positions in the **same component** will have the **same crystal count**.
        
    *   We can precompute and store these values for efficiency.
        
2.  **Efficient Computation**
    
    *   Instead of running a **BFS/DFS for each query**, we can **precompute** the crystal count for each connected component **once** and then answer each query in **O(1)** time.
        

**Solution Approach**
---------------------

### **Step 1: Precompute Connected Components using BFS/DFS**

*   Traverse the grid and **identify each connected component**.
    
*   For each **new component**, use **BFS (or DFS)** to:
    
    *   Count the number of **crystals ('C')** in that component.
        
    *   Mark all reachable positions in that component with the **same crystal count**.
        

### **Step 2: Answer Queries in O(1)**

*   After precomputing, each cell (xi, yi) will already have an **associated crystal count**.
    
*   Simply **return the precomputed value** for each query.
    

**Implementation Details**
--------------------------

1.  **Use a visited array** to track visited cells.
    
2.  **BFS (or DFS) for connected component exploration**:
    
    *   Use a queue (for BFS) or recursion (for DFS) to explore the component.
        
    *   Count the number of 'C' cells in the component.
        
    *   Store the count in a component\_crystals map.
        
3.  **Store results in an array** so that each query is answered in O(1).
    

**Time Complexity Analysis**
----------------------------

*   **Finding components (BFS/DFS)**:
    
    *   Each cell is visited **once**, so it takes **O(M × N)**.
        
*   **Querying results**:
    
    *   Each query is answered in **O(1)**.
        
*   **Total Complexity**:
    
    *   **O(M × N) + O(Q)**, which is highly efficient. </br>

## Implement using DFS : 
```
#include<bits/stdc++.h>
using namespace std ;

const int mx = 500;
char ch[mx][mx];
int vis[mx][mx];
int crystal_cnt[mx][mx];
int n , m , q ;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid( int nx , int ny ){
    return (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && ch[nx][ny] != '#');
}

int dfs( int x , int y , vector<pair<int,int>>&com ){
    vis[x][y] = true ;
    com.push_back({x ,y});
    
     int ans = (ch[x][y] == 'C' ? 1 : 0);
    for ( auto [dx , dy] : dir ){
        int nx = x+dx , ny = y + dy;
        if( isValid(nx , ny )){
            ans += dfs( nx , ny , com );
        }
    }
    return ans ;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc ; cin>> tc ;
    for ( int i = 1 ; i <= tc ; i++ ){
        cin>> n >> m >> q ;
        for ( int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++ ){
                cin>> ch[i][j];
            }
        }
        memset(crystal_cnt , 0 , sizeof(crystal_cnt));
        memset(vis , 0 , sizeof(vis));

        for ( int i = 0 ; i < n ; i++ ){ // pre calculation 
            for ( int j = 0 ; j < m ; j++ ){
                if ( !vis[i][j] && ch[i][j] != '#'){
                    vector<pair<int,int>> con_com;
                    int crystal = dfs(i , j , con_com);

                    for ( auto [x,y] : con_com){
                        crystal_cnt[x][y] = crystal;
                    }
                }
            }
        }
        cout << "Case " << i << ": " << '\n';
        for ( int i = 0 ; i < q ; i++ ){
            int x , y ;
            cin>> x >> y ;
            x--;y--;
            cout << crystal_cnt[x][y] << '\n';
        }
    }
    
    return 0 ;
}
/// Date : 08-03-2025
```

## Implementing using BFS : 
```
#include<bits/stdc++.h>
using namespace std ;

const int mx = 500;
char ch[mx][mx];
int vis[mx][mx];
int crystal_cnt[mx][mx];
int n , m , q ;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid( int nx , int ny ){
    return (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && ch[nx][ny] != '#');
}

void bfs ( int x , int y){
    queue<pair<int,int>>q ;
    vis[x][y] = true ;
    q.push({ x , y });

    vector<pair<int,int>>con_com;
    int crystal = 0 ;

    while ( !q.empty()){

        auto[x,y] = q.front();
        q.pop();
        if ( ch[x][y] == 'C'){
            crystal++;
        }
        con_com.push_back({ x , y });

        for ( auto [dx , dy] : dir){
            int nx = x + dx , ny = y + dy ;
            if ( isValid(nx , ny )){
                vis[nx][ny] = true ;
                q.push({ nx, ny });
            }
        }
    }

    for ( auto [x , y] : con_com){
        crystal_cnt[x][y] = crystal;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc ; cin>> tc ;
    for ( int i = 1 ; i <= tc ; i++ ){
        cin>> n >> m >> q ;
        for ( int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++ ){
                cin>> ch[i][j];
            }
        }
        memset(crystal_cnt , 0 , sizeof(crystal_cnt));
        memset(vis , 0 , sizeof(vis));

        for ( int i = 0 ; i < n ; i++ ){ // pre calculation 
            for ( int j = 0 ; j < m ; j++ ){
                if ( !vis[i][j] && ch[i][j] != '#'){
                    bfs(i , j );
                }
            }
        }
        cout << "Case " << i << ": " << '\n';
        for ( int i = 0 ; i < q ; i++ ){
            int x , y ;
            cin>> x >> y ;
            x--;y--;
            cout << crystal_cnt[x][y] << '\n';
        }
    }
    
    return 0 ;
}
/// Date : 08-03-2025
```