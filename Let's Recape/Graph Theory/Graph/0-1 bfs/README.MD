# 0-1 BFS Algorithm #
This implementation finds the shortest path in an unweighted or 0-1 weighted graph using a deque (double-ended queue). It is an optimized approach for graphs where edges have only 0 or 1 weights.
</br>
Note : We can convert any problem if we need to find the shortest path and there is only 2 weight.

## Algorithm Explanation ## 
- Graph Representation : </br>
1 . The graph is stored as an adjacency list where each node connects to a list of {neighbor, weight} pairs.</br>
2 . If an edge has weight 0, it is processed first (pushed to the front of the queue).</br>
3 . If an edge has weight 1, it is processed later (pushed to the back of the queue).
- Initialization : </br>
1 . d[i] stores the shortest distance to node i, initialized to INF (1e9).</br>
2 . The source node (1) is pushed to the front of the deque with a distance of 0.
- Deque Processing: </br>
1 . Nodes are processed in BFS order, prioritizing 0-weight edges before 1-weight edges.</br>
2 . If visiting a neighbor v via u gives a shorter path, update d[v]: </br>
   * If w == 0, push v to the front (higher priority).
   * If w == 1, push v to the back (lower priority).
- Final Output : </br>
1 . d[n] gives the shortest path from 1 to n.</br>
2 . If n is unreachable, return -1. </br>

## When to Use 0-1 BFS? ## 
- When the graph contains only 0 and 1 edge weights.
- Faster than Dijkstra’s Algorithm for such graphs (O(V + E) time complexity).
## Complexity Analysis ## 
Time Complexity: O(V + E)</br>
Space Complexity: O(V)

## Implementation ##
```
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 123;
const int INF = 1e9; 
vector<pair<int, int>> g[mx];
vector<int> d(mx, INF); 

int n, m;

int bfs() {
    deque<int> dq;
    dq.push_front(1); 
    d[1] = 0;
    
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (auto edge : g[u]) {
            int v = edge.first;
            int w = edge.second;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (w == 0) 
                    // Prioritize 0-weight edges
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }
    return d[n] == INF ? -1 : d[n]; // Return -1 if cant reach n form 1
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1}); 
    }
    
    int mn_cost = bfs();
    cout << mn_cost << "\n"; 
    
    return 0;
}
```

