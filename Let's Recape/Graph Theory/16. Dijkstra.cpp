Code 01 : Dijkstra with priority_queue(min heap)
Time Compexity : O(ElogV)

#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 123;
const long long INF = 1e17;
vector<pair<int, int>> g[mx];
long long dis[mx];
int n, m;

void dijkstra(int src)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        auto [cur_dis, cur_node] = pq.top();
        pq.pop();

        if (cur_dis > dis[cur_node]) continue;

        for (auto it : g[cur_node])
        {
            auto adj_node = it.first ;
            auto weight = it.second ;

            if (cur_dis + weight < dis[adj_node])
            {
                dis[adj_node] = cur_dis + weight;
                pq.push({dis[adj_node], adj_node});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }

    fill(dis, dis + n + 1, INF);
    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << '\n';

    return 0;
}


Code 02 : Dijkstra with set
Time Compexity : O(ElogV)
