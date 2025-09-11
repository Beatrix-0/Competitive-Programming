[Problem](https://codeforces.com/gym/101532/problem/D)

```cpp
#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--) {
        int n, q;
        cin >> n >> q;
        string x; cin >> x;
        string s = "$" + x;

        vector<vector<int>> pref(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; i++) {
            for (int c = 0; c < 26; c++){
                pref[i][c] = pref[i - 1][c];
            }
            pref[i][s[i] - 'a']++;
        }

        int cnt[26] = {0};
        for (int i = 1; i <= n; i++)
            cnt[s[i] - 'a']++;

        auto F = [&](int R, int c) -> int {
            if (R <= 0) return 0;
            int repeat = R / n;
            int rem = R % n;
            return repeat * cnt[c] + pref[rem][c];
        };

        while(q--) {
            int l, r;
            char ch;
            cin >> l >> r >> ch;
            int c = ch - 'a';
            cout << F(r, c) - F(l - 1, c) << "\n";
        }
    }
    return 0;
}
```
