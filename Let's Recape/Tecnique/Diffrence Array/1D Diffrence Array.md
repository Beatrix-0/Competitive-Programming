```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> diff(n + 2, 0);

    while (q--) {
        int l, r;
        int val;
        cin >> l >> r >> val;
        diff[l] += val;
        diff[r + 1] -= val;
    }

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + diff[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << pre[i] << " ";
    }
}
```

## Application :

1. Perform multiple range updates efficiently (add/subtract a value in [l, r])
2. Sometimes used in 2D grids for fast rectangle updates.
