#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count(ll n, ll k) {
    ll ans = ((n + 1) >> (k + 1)) << k;
    if ((n + 1) & (1LL << k)) {
        ans = ans + ((n + 1) & ((1LL << k) - 1));
    }
    return ans;
}

ll f(ll l, ll r) {
    ll ans = 0;
    for (ll k = 31; k >= 0; k--) {
        if (count(r, k) - count(l - 1, k) == (r - l + 1)) {
            ans |= (1LL << k);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        cout << f(l, r) << '\n';
    }
    
    return 0;
}
