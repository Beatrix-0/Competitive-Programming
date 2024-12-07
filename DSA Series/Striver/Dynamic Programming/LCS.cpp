#include <bits/stdc++.h>
using namespace std;

const int mx = 1e3 + 123;
int dp[mx][mx];
int n, m;

int lcs(int i, int j, const string &a, const string &b)
{
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j])
    {
        return dp[i][j] = 1 + lcs(i - 1, j - 1, a, b);
    }
    else
    {
        return dp[i][j] = max(lcs(i - 1, j, a, b), lcs(i, j - 1, a, b));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    n = a.size();
    m = b.size();
    memset(dp, -1, sizeof(dp));
    cout << lcs(n - 1, m - 1, a, b) << '\n';

    return 0;
}
