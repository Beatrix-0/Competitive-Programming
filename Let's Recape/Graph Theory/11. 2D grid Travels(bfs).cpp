#include <bits/stdc++.h>
using namespace std;

const int mx = 1001;
const int INF = 1e9;
int n, m;
int dis[mx][mx];
bool vis[mx][mx];

bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int srcX, int srcY)
{
    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = true;
    dis[srcX][srcY] = 0;

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];

            if (isValid(newX, newY) && !vis[newX][newY])
            {
                q.push({newX, newY});
                vis[newX][newY] = true;
                dis[newX][newY] = dis[curX][curY] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dis[i][j] == INF) cout << "-1 ";
            else cout << dis[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    memset(dis, INF, sizeof(dis));
    memset(vis, false, sizeof(vis));

    bfs(0, 0);

    return 0;
}
