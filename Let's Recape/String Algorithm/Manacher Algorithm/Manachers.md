# Manacher's algorithm

## Resouces

[Video](https://youtu.be/egkR87tSnd4?si=9N2MPzn7Qdm9AZPh)

## Practice problem

[Longest Palindrome](https://cses.fi/problemset/task/1111/)

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Manacher {
    string tmp;
    vector<int> p;
    Manacher(string s) {
        tmp = "#";
        for (auto c : s) {
            tmp += c;
            tmp += '#';
        }
        int n = tmp.size();
        p.assign(n, 0);
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (i < c + p[c]) {
                p[i] = min(c + p[c] - i, p[2 * c - i]);
            }
            int l = i - p[i] - 1;
            int r = i + p[i] + 1;
            while (l >= 0 && r < n && tmp[l] == tmp[r] ){
                p[i]++;
                l--;
                r++;
            }
            if (i + p[i] > c + p[c]) {
                c = i;
            }
        }
    }
    pair<int,int> longest_palindrome() {
        int mx = 0;
        int ind = 0;
        int n = p.size();
        for (int i = 0; i < n; i++) {
            if (p[i] > mx) {
                mx = p[i];
                ind = i;
            }
        }
        int start = (ind - mx) / 2;
        return {start, mx};
    }
    bool is_palindrome(int l, int r) {
        int len = r - l + 1;
        int mid = l + r + 1;
        return p[mid] >= len;
    }
};

void solve() {

    string s; cin >> s;
    Manacher M(s);
    auto [st, len] = M.longest_palindrome();
    cout << s.substr(st, len) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests = 1;
    // cin >> tests;
    for ( int tc = 1 ; tc <= tests ; tc++ ){
        solve();
    }
    return 0;
}
```
