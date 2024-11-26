#include<bits/stdc++.h> // Code 
using namespace std ;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);

const int N = 2e5 + 5;
vector<int> g[N];
int col[N];
int vam, lyk;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    col[u] = 1;
    vam++;
    
    while (!q.empty())
    {
        int x = q.front(); 
        q.pop();
        
        for (int i = 0; i < g[x].size(); i++) 
        {
            int xx = g[x][i]; // child
            if (col[xx] == 0)
            {
                if (col[x] == 1)
                {
                    q.push(xx);
                    col[xx] = 2;
                    lyk++;
                }
                else
                {
                    q.push(xx);
                    col[xx] = 1;
                    vam++;
                }
            }
        }
    }
}

void clr()
{
    for (int i = 1; i < N; i++)
    {
        g[i].clear();
        col[i] = 0;
    }
}

int main()
{
    fast; 
    int t;
    cin >> t;
    
    for ( int i = 1 ; i <= t ; i++ )
    {
        clr();
        int m;
        cin >> m;
        
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        int ans = 0;
        
        for (int i = 1; i < N; i++)
        {
            if (col[i] == 0 && !g[i].empty()) 
            {
                vam = 0;
                lyk = 0;
                bfs(i);
                ans += max(vam, lyk); 
            }
        }
        
        cout << "Case " << i << ": " << ans << '\n';
    }
    
    return 0;
}
