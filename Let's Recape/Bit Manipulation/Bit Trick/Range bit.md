[J. Bit Lobon](https://codeforces.com/gym/106045/problem/J) </br>
[C. Interesting Sequence](https://codeforces.com/problemset/problem/1775/C)

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Counts the number of integers in [0, n] that have the k-th bit set.
int count_bit(int n, int k) {
    if (n < 0) return 0;
    int cycle = 1LL << (k+1);
    int full_cycles = (n + 1) / cycle;
    int count = full_cycles * (1LL << k);
    int remainder = (n + 1) % cycle;
    if (remainder > (1LL << k)) {
        count += remainder - (1LL << k);
    }
    return count;
}

// Computes the bitwise AND of all integers from l to r.
int range_and(int l, int r) {
    int ans = 0;
    int total = r - l + 1;
    for (int k = 0; k < 60; k++) {
        int cnt_r = count_bit(r, k);
        int cnt_l_minus = (l == 0) ? 0 : count_bit(l-1, k);
        if (cnt_r - cnt_l_minus == total) {
            ans |= (1LL << k);
        }
    }
    return ans;
}

// Computes the bitwise OR of all integers from l to r.
int range_or(int l, int r) {
    int ans = 0;
    for (int k = 0; k < 60; k++) {
        int cnt_r = count_bit(r, k);
        int cnt_l_minus = (l == 0) ? 0 : count_bit(l-1, k);
        if (cnt_r - cnt_l_minus > 0) {
            ans |= (1LL << k);
        }
    }
    return ans;
}

// Computes the bitwise XOR of all integers from l to r.
int range_xor(int l, int r) {
    int ans = 0;
    for (int k = 0; k < 60; k++) {
        int cnt_r = count_bit(r, k);
        int cnt_l_minus = (l == 0) ? 0 : count_bit(l-1, k);
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
        int l, r;
        cin >> l >> r;
        int A = range_and(l, r);
        int O = range_or(l, r);
        int X = range_xor(l, r);
        cout << A << " " << O << " " << X << "\n";
    }

    return 0;
}
```
