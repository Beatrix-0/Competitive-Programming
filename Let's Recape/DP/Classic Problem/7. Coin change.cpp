#include <bits/stdc++.h>
using namespace std;

const int N = 500;
int x, n, c[N], dp[N], inf = 1e9 + 7;

int mn_coin(int amount)
{
    if (amount < 0) return inf;
    if (amount == 0) return 0;
    if (dp[amount] != -1) return dp[amount];

    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, mn_coin(amount - c[i]) + 1);
    }
    return dp[amount] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> x >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    memset(dp, -1, sizeof(dp));
    int res = mn_coin(x);

    if (res >= inf)
    {
        cout << "Not possible !" << '\n';
    }
    else
    {
        cout << "Possible !" << '\n';
        cout << res << '\n';
    }

    return 0;
}
