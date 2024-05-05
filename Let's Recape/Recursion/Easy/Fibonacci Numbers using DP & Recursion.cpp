#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (dp[n] != -1) return dp[n];

    return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    int ans = solve(n, dp);

    cout << ans << '\n';

    return 0;
}
