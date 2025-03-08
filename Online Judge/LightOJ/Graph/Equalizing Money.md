**Distributing Money Equally in a Village**
===========================================

**Observations and Solution**
-----------------------------

The problem can be visualized as an **undirected graph**, where each person is a node, and an edge between two nodes means they can exchange money freely. The key observations are:

1.  **Connected Components Matter**
    
    *   People can only distribute money among themselves if they are **connected** in the given relations.
        
    *   If a person is in a different connected component, their money cannot be redistributed to another component.
        
2.  **Total Money in a Component**
    
    *   For each connected component, we sum up the total money and check if it is **evenly divisible** by the number of people in that component.
        
    *   If the sum is not divisible, it is **impossible** to equalize money in that component.
        
3.  **Final Check**
    
    *   If all connected components have an equal distribution, the answer is "Yes", otherwise "No".
        

**Implementation Details**
--------------------------

1.  **Graph Representation**
    
    *   We use an adjacency list to store the relationships.
        
    *   Perform **DFS** (or BFS) to find all connected components.
        
2.  **DFS Traversal**
    
    *   Run DFS to explore each component and store the nodes belonging to it.
        
3.  **Validation**
    
    *   Compute the total sum of money in each component.
        
    *   Check if this sum is divisible by the size of the component.
        
    *   Ensure that every component gets the same equalized amount.
        

### **Algorithm Steps**

1.  Read n (number of people) and m (number of relations).
    
2.  Read the initial money each person has.
    
3.  Construct the adjacency list for relationships.
    
4.  Use **DFS** to find all connected components.
    
5.  For each component, compute:
    
    *   **Total sum of money**
        
    *   **Size of the component**
        
    *   **Check divisibility**
        
6.  If all components satisfy the condition, print "Yes", otherwise "No".
    

**Time Complexity Analysis**
----------------------------

*   **DFS Traversal**: O(n + m), since each edge and node is visited once.
    
*   **Summation and Checking**: O(n), since we iterate through all nodes.
    
*   **Total Complexity**: O(n + m), which is optimal for n ≤ 1000 and m ≤ 10000.

## Implementation using Dfs :
```
#include <bits/stdc++.h>
using namespace std;

const int mx = 1000 + 123;
vector<int> g[mx];
vector<int> vis(mx, 0);

#define int long long 

void dfs(int u, int cnt, vector<vector<int>>& con_com) {
    vis[u] = 1;
    con_com[cnt].push_back(u);
    for (auto v : g[u]) {
        if (!vis[v]) {
            dfs(v, cnt, con_com);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, m;
        cin >> n >> m;

        vector<int> money(n + 1);
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        fill(vis.begin(), vis.begin() + n + 1, 0);

        int total_money = 0;
        for (int i = 1; i <= n; i++) {
            cin >> money[i];
            total_money += money[i];
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (total_money % n != 0) { 
            cout << "Case " << t << ": No" << '\n';
            continue;
        }

        // value that should be same for all node  
        int target = total_money / n; 
        vector<vector<int>> con_com; 
        con_com.resize(n); 

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                con_com[cnt].clear();
                dfs(i, cnt, con_com);
                cnt++;
            }
        }

        bool possible = true;
        for (int i = 0; i < cnt; i++) {
            int sum = 0;
            for (auto person : con_com[i]) {
                sum += money[person];
            }
            int size = con_com[i].size();
            if (sum % size != 0 || sum / size != target) {
                possible = false;
                break;
            }
        }

        cout << "Case " << t << ": " << (possible ? "Yes" : "No") << '\n';
    }

    return 0;
}
```
