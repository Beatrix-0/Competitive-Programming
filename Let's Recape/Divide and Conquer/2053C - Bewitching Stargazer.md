```cpp
// problem : https://codeforces.com/problemset/problem/2053/C
#include<bits/stdc++.h> 
using namespace std;

#define int long long 
pair<int, int> yo(int l, int r, int k) {
    if (r - l + 1 < k) return {0, 0};

    int mid = (l + r) / 2;
    if ((r - l + 1) % 2) { 
        pair<int, int> val = yo(l, mid - 1, k);
        // val.first = Left half ans 
        // val.seconf = Left half element size
        // formula for generate all ans in full segment using left ans
        int sum = (val.first * 2) + (mid * val.second) + mid;
        int segSize = val.second * 2 + 1;
        return {sum, segSize};
    } else {
        pair<int, int> val = yo(l, mid, k);
        int sum = (val.first * 2) + (mid * val.second);
        int segSize = val.second * 2;
        return {sum, segSize};
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        int n, k;
        cin >> n >> k;
        pair<int, int> ans = yo(1, n, k);
        cout << ans.first << '\n';
    }

    return 0;
}
```