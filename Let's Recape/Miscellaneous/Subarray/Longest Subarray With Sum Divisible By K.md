## Longest Subarray Length With Sum Divisible By K

[Video Tutoral](https://youtu.be/hviDtcBVpho?si=K1PD_GlhUegOs6xb)

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , k ;
    cin >> n >> k ;

    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<int> vis(k, -1);
    int pref = 0;
    int len = 0;

    for (int i = 1; i <= n; i++) {
        pref += v[i];
        int m = pref % k;

        if (m == 0) {
            len = max(len, i);
        } else {
            if (vis[m] != -1) {
                len = max(len, i - vis[m]);
            } else {
                vis[m] = i;
            }
        }
    }

    cout << len << "\n";

    return 0;
}
```
