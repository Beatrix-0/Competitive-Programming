# Calculating Level of a Tree Using DFS
In a tree, the level of a node is defined as the number of edges from the root node. The root node is typically assigned level 0 (or 1, depending on convention), and each child node’s level is one more than its parent's level.

This implementation uses Depth-First Search (DFS) to efficiently determine the level of each node in an undirected tree.</br>


## Approach
- Construct the tree using an adjacency list.
- Start DFS from the root node (usually node 1), initializing its level to 0.
- For each adjacent child node, set its level as parent_level + 1.
- Recursively traverse all child nodes.
- To prevent revisiting the parent node, pass the parent as a parameter and skip it in recursion.( if the tree is directed no need to use visited array ) </br>

## Implementation 
```
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;  
vector<int> tree[N];    
int level[N];          

void dfs(int node, int parent, int depth) {
    level[node] = depth; 
    for (int child : tree[node]) {
        if (child != parent) { // if directed not need to check the condition 
            dfs(child, node, depth + 1);
        }
    }
}

int main() {
    int n; 
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, -1, 0);
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " is at level " << level[i] << "\n";
    }

    return 0;
}
```
Time complexity : O(U+V)