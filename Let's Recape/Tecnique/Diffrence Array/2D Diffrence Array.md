[Problem](https://vjudge.net/problem/USACO-919)

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MX = 1002;
int diff[MX][MX];
int pre[MX][MX];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        int x1, y1, x2, y2; // 0 based index
        cin >> x1 >> y1 >> x2 >> y2;

        x1++, y1++, x2++, y2++; // converting 1 based index

        diff[x1][y1] += 1;
        diff[x2][y1] -= 1;
        diff[x1][y2] -= 1;
        diff[x2][y2] += 1;
    }

    int ans = 0;
    for (int i = 1; i <= 1001; i++) {
        for (int j = 1; j <= 1001; j++) {
            pre[i][j] = diff[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            if (pre[i][j] == K) ans++; // based on condition
        }
    }

    cout << ans << "\n";
    return 0;
}
```
