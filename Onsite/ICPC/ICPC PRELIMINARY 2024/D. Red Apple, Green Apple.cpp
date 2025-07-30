#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int mod = 998244353;

int power(int a, int n, int mod) {
    if (n == 0) return 1;
    int res = 1;
    a %= mod;
    while (n > 0) {
        if (n % 2) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        n /= 2;
    }
    return res;
}

int inverse(int a, int mod) {
    return power(a, mod - 2, mod); 
}

int modmul(int a, int b) {
    return ((1LL * a % mod) * (b % mod)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> r(n), g(n);
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < n; i++) cin >> g[i];

    int appleW = 0;
    for (int i = 0; i < n; i++) {
        appleW = (appleW + r[i] + g[i]) % mod;
    }

    int inv2n = inverse(2 * n , mod); 

    for (int k = 1; k <= n; k++) {
        int res = modmul(k, appleW);    
        res = modmul(res, inv2n);         
        cout << res << " ";
    }

    return 0;
}
