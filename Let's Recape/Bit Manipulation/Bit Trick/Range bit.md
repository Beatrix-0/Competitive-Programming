[Problem](https://codeforces.com/gym/106045/problem/J)

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Counts the number of integers in [0, n] that have the k-th bit set.
ll count_bit(ll n, ll k) {
    if (n < 0) return 0;
    ll cycle = 1LL << (k+1);
    ll full_cycles = (n + 1) / cycle;
    ll count = full_cycles * (1LL << k);
    ll remainder = (n + 1) % cycle;
    if (remainder > (1LL << k)) {
        count += remainder - (1LL << k);
    }
    return count;
}

// Computes the bitwise AND of all integers from l to r.
ll range_and(ll l, ll r) {
    ll ans = 0;
    ll total = r - l + 1;
    for (ll k = 0; k < 60; k++) {
        ll cnt_r = count_bit(r, k);
        ll cnt_l_minus = (l == 0) ? 0 : count_bit(l-1, k);
        if (cnt_r - cnt_l_minus == total) {
            ans |= (1LL << k);
        }
    }
    return ans;
}

// Computes the bitwise OR of all integers from l to r.
ll range_or(ll l, ll r) {
    ll ans = 0;
    for (ll k = 0; k < 60; k++) {
        ll cnt_r = count_bit(r, k);
        ll cnt_l_minus = (l == 0) ? 0 : count_bit(l-1, k);
        if (cnt_r - cnt_l_minus > 0) {
            ans |= (1LL << k);
        }
    }
    return ans;
}

// Computes the bitwise XOR of all integers from l to r.
ll range_xor(ll l, ll r) {
    ll ans = 0;
    for (ll k = 0; k < 60; k++) {
        ll cnt_r = count_bit(r, k);
        ll cnt_l_minus = (l == 0) ? 0 : count_bit(l-1, k);
        if ((cnt_r - cnt_l_minus) % 2 == 1) {
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
        ll A = range_and(l, r);
        ll O = range_or(l, r);
        ll X = range_xor(l, r);
        cout << A << " " << O << " " << X << "\n";
    }
    
    return 0;
}
```