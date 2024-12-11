#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 123;
vector<int> g[mx];
bool vis[mx];
bool path[mx];
int par[mx];
int n, m;
int st_cycle = -1, ed_cycle = -1;

bool dfs(int u)
{
    vis[u] = true;
    path[u] = true ;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            par[v] = u;
            if (dfs(v))
            {
                return true;
            }
        }
        else if (path[v] == true && vis[v] == true )
        {
            st_cycle = v;
            ed_cycle = u;
            return true;
        }
    }
    path[u] = false ;
    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i))
            {
                break;
            }
        }
    }

    if (st_cycle == -1)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        vector<int> path;
        path.push_back(st_cycle);
        for (int u = ed_cycle; u != st_cycle; u = par[u])
        {
            path.push_back(u);
        }
        path.push_back(st_cycle);
        reverse(path.begin(), path.end());

        cout << path.size() << '\n';
        for (auto it : path)
        {
            cout << it << " ";
        }
        cout << '\n';
    }

    return 0;
}

/*Input:

4 5
1 3
2 1
2 4
3 2
3 4*/
// Video : https://youtu.be/9twcmtQj4DU?si=5U3iD6ZU90ufM70b
// Problem : https://cses.fi/problemset/task/1678