``` 
#include <bits/stdc++.h>
using namespace std;
const int mx = 1001;
const int MOD = 10056;

#define int long long 
int stirling[mx][mx], fact[mx];
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < mx; i++)
        fact[i] = (fact[i - 1]* 1LL * i) % MOD;

    // Compute Stirling numbers of the second kind
    stirling[0][0] = 1;
    for (int n = 1; n < mx; n++) {
        for (int k = 1; k <= n; k++) {
            stirling[n][k] = (stirling[n - 1][k - 1] + k * stirling[n - 1][k]) % MOD;
        }
    }
}


signed main() {

    precompute();

    int tc ; 
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        int n ; cin >> n;
        int ways = 0 ;
        for ( int i = 1 ; i <= n ; i++ ){
            ways = (ways + stirling[n][i] * 1LL * fact[i])% MOD;
        }
        cout << "Case " << i << ": " << ways << "\n";
    }
    
    return 0;
}
```