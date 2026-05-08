# Manacher's algorithm

## Resouces

[Video](https://youtu.be/egkR87tSnd4?si=9N2MPzn7Qdm9AZPh)

## Practice problem

[Longest Palindrome](https://cses.fi/problemset/task/1111/)

## Code 01

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

## Code 02

```cpp
#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    string s; cin >> s;
    Manacher M(s);
    cout << M.longest() << '\n';
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
