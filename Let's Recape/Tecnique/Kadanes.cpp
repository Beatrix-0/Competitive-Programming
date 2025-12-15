#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "trace.cpp"
#else
#define dbg(...)
#endif

void solve() {
    int n; cin >> n ;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int current_sum = v[0];
    int max_sum = v[0];
    for (int i = 1; i < n; i++) {
        current_sum = max(v[i], current_sum + v[i]);
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests = 1;
    cin >> tests;
    for ( int tc = 1 ; tc <= tests ; tc++ ){
        solve();
    }
    return 0;
}