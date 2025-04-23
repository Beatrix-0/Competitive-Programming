// Time compexity : O(n^3)

#include<bits/stdc++.h>
using namespace std;

const int mx = 500 + 12;
const long long INF = 1e17 + 123;
long long dis[mx][mx];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }

    for (int j = 0; j < m; j++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        dis[u][v] = min(dis[u][v] , 1LL*wt);
        dis[v][u] = min(dis[v][u] , 1LL*wt);
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    while (q--)
    {
        int u1, v1;
        cin >> u1 >> v1;
        if (dis[u1][v1] == INF)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << dis[u1][v1] << '\n';
        }
    }

    /// Optional cycle detection
    /*for (int i = 1; i <= n; i++) {
        if (dis[i][i] < 0) {
            cout << "Cycle Exist" << '\n';
            break;
        }
    }*/

    return 0;
}

// Video : - https://youtu.be/oNI0rf2P9gE?si=sOfw8FcAUPam9fK_ 
//         - https://youtu.be/YbY8cVwWAvw?si=c3RuAN80icKid7kM
// Problem : https://cses.fi/problemset/result/11407015/ 