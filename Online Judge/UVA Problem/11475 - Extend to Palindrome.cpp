#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "trace.cpp"
#else
#define dbg(...)
#endif

struct Manacher {
    vector<int> odd, even;
    int n;
    string s;
    Manacher(string _s) {
        s = _s;
        n = s.size();
        odd.assign(n, 0);
        even.assign(n, 0);
        build();
    }
    void build() { 
        // odd len palindromes
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            if (i > r) {
                odd[i] = 1;
            }
            else {
                int mirror = l + r - i;
                odd[i] = min(odd[mirror], r - i + 1);
            }
            while (i - odd[i] >= 0 && i + odd[i] < n && s[i - odd[i]] == s[i + odd[i]] ){
                odd[i]++;
            }

            if (i + odd[i] - 1 > r) {
                l = i - odd[i] + 1;
                r = i + odd[i] - 1;
            }
        }

        // even len palindromes
        l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            if (i > r) {
                even[i] = 0;
            }
            else {
                int mirror = l + r - i + 1;
                even[i] = min(even[mirror], r - i + 1);
            }

            while (i - even[i] - 1 >= 0 && i + even[i] < n && s[i - even[i] - 1] == s[i + even[i]]){
                even[i]++;
            }
            if (i + even[i] - 1 > r) {
                l = i - even[i];
                r = i + even[i] - 1;
            }
        }
    }

    // longest palindrome length
    int longest() {
        int mx = 1;
        for (int i = 0; i < n; i++) {
            mx = max(mx, 2 * odd[i] - 1);
            mx = max(mx, 2 * even[i]);
        }
        return mx;
    }

    bool is_palindrome(int l, int r) {
        int len = r - l + 1;
        int mid = (l + r) / 2;
        if (len & 1) {
            return (2 * odd[mid] - 1 >= len);
        }
        else {
            mid++;
            return (2 * even[mid] >= len);
        }
    }
};

void solve(string s ) {
    Manacher M(s);
    auto v1 = M.even;
    auto v2 = M.odd;
    int n = s.size();

    dbg(v1);
    dbg(v2);

    int ind = n+1;
    for ( int i = 0 ; i < n ; i++ ){
        if (v1[i]+i == n ){
            ind = min( ind , i - v1[i]);
            break;
        } 
    }
    for ( int i = 0 ; i < n ; i++ ){
        if (v2[i]+i == n ){
            ind = min( ind , i - (v2[i]-1) );
            break;
        }
    }
    string tmp = "";
    for ( int i = 0 ; i < ind ; i++ ){
        tmp += s[i];
    }
    reverse(tmp.begin() , tmp.end());
    s += tmp;
    cout << s << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while(cin >> s ){
        solve(s);
    }
    return 0;
}