```cpp
#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map<int,int> mp;
    mp[0] = 1;

    int pref = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        pref += v[i];
        int mod = ((pref % n) + n) % n; // for neg mod

        ans += mp[mod];
        mp[mod]++;
    }

    cout << ans << '\n';
    return 0;
}
```
