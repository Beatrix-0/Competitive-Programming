#include <bits/stdc++.h>
using namespace std;

#define int long long
bool check(int y, vector<int>& a, vector<int>& b, int m) {
    int totDollar = 0;
    for (int i = 0; i < a.size(); i++) {
        int lira = y / b[i];
        int dollar = max(0LL, a[i] - lira); // dollar have to give in ith day
        totDollar += dollar;
        if (totDollar > m) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int l = 0, r = 1e18, ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, a, b, m)) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}