#include <bits/stdc++.h>
using namespace std;

// Function to handle negative modulo
int safemod(int x, int MOD)
{
    int y = x % MOD;
    if (y < 0)
    {
        y += MOD;
    }
    return y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, MOD;
    cin >> x >> MOD;

    int res = safemod(x, MOD);
    cout << res << '\n';

    return 0;
}
