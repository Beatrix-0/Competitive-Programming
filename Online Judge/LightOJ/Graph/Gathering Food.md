**Problem Breakdown**
---------------------

Winter is approaching, and Yogi Bear needs to collect all the food before hibernation. The food is scattered across an **N × N** grid. Each cell in the grid represents:

*   . → An **empty space** (can move here).
    
*   \# → An **obstacle** (cannot move through).
    
*   \[A-Z\] → A **food item** (must collect in order).
    

Yogi **must start at 'A'** and collect the food **in order** (i.e., A → B → C → ...). The goal is to find the **minimum number of moves** required to collect all the food in order. If it's **impossible** to collect all, print "Impossible".

### **Constraints**

*   1 ≤ T ≤ 200 (Test cases)
    
*   1 ≤ N ≤ 10 (Grid size)
    
*   **All letters are distinct** and from the first k alphabets (A, B, C, ..., k).
    

**Understanding the Movement**
------------------------------

*   Yogi can move **up, down, left, or right**.
    
*   He **must follow the order** while collecting food.
    
*   He **cannot cross obstacles (#)**.
    
*   He **cannot move past an uncollected food item** (e.g., if he hasn’t collected B, he can't walk over C).
    

**Approach to Solve the Problem**
---------------------------------

### **Step 1: Read the Input**

*   Read N (size of the grid).
    
*   Store the grid and **find the starting position (A)**.
    
*   Count how many **food items** exist (k).
    

### **Step 2: Use BFS to Find the Shortest Paths**

*   Start BFS from A to B, then from B to C, and so on.
    
*   **Why BFS?** BFS guarantees the shortest path in an **unweighted** grid.
    
*   Track visited cells (vis\[\]\[\]) and distance (dist\[\]\[\]).
    

### **Step 3: Process Each Food Item Sequentially**

1.  **Find the shortest path to the next food item** (BFS from current position).
    
2.  **If the next food is unreachable**, print "Impossible" and stop.
    
3.  **Otherwise, add the distance to the total moves**.
    
4.  **Update the starting position** to the newly collected food.
    
5.  Repeat until all food items are collected.
    

**Complexity Analysis**

*   **BFS Time Complexity:** O(N2)O(N^2)O(N2) (worst case for each food item)
    
*   **Total BFS Runs:** At most **26** (A-Z)
    
*   **Overall Complexity:** O(26×N2)O(26 \\times N^2)O(26×N2)Since N≤10N \\leq 10N≤10, this is **efficient**.

## Implementation with Bfs : 
```
#include <bits/stdc++.h>
using namespace std;

const int mx = 11;
int n;
char ch[mx][mx];
bool vis[mx][mx];
int dis[mx][mx];
int sc_x, sc_y;
char dest;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Check if the next cell is valid
bool isValid(int nx, int ny) {
    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny] && ch[nx][ny] != '#') {
        if ((ch[nx][ny]>dest && dest<='Z') || (ch[nx][ny]>dest=='#')) {
            return false;
        }
        else {
            return true ;
        }
    }
    return false;
}

// BFS to find shortest path from (x, y) to the next destination
int bfs(int x, int y) {
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));

    vis[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    dis[x][y] = 0;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        if (ch[cx][cy] == dest) {
            /// get new source's x and y .
            sc_x = cx, sc_y = cy; 
            return dis[cx][cy];
        }

        for (auto [dx, dy] : dir) {
            int nx = cx + dx, ny = cy + dy;
            if (isValid(nx, ny)) {
                vis[nx][ny] = true;
                dis[nx][ny] = dis[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1; // No path found
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n;
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> ch[i][j];
                if (ch[i][j] == 'A') {
                    /// finding first charcater
                    sc_x = i, sc_y = j;
                }
                if (isupper(ch[i][j])) {
                    cnt++; 
                }
            }
        }

        cnt--;
        int res = 0;
        bool ok = true;
        /// when source is A then destination is B
        dest = 'B'; 

        for (int i = 0; i < cnt; i++) { 
            /// every time ,get new source_x and source_y( updated in bfs function )
            int cost = bfs(sc_x, sc_y);
            if (cost == -1) {
                ok = false;
                break;
            }
            res += cost;
            /// destination changed
            dest++;
        }

        cout << "Case " << t << ": ";
        if (ok) {
            cout << res << '\n';
        } else {
            cout << "Impossible\n";
        }
    }
    return 0;
}
/// Date : 08-03-2025
```