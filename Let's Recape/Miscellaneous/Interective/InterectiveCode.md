# Interective Problem

An interactive problem is a type of competitive programming or algorithmic problem where your program communicates back and forth with a judge (judge is me) in real time. Instead of reading all input at once and printing the final answer, your program:

1. Reads some information from the judge (ask function)
2. Makes a query or guess
3. Receives feedback from the judge
4. Repeats until the problem is solved

<br>

Problem : [Hidden Integer(CSES)](https://cses.fi/problemset/task/3112/)

```cpp
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "trace.cpp"
#else
#define dbg(...)
#endif

string ask(int num) {
    cout << "? " << num << endl;

    string s; // judge(me) giving input ("<",">=" )
    if (!(cin >> s)) {
        exit(0);
    }
    return s;
}

void solve() {
    int l = 1, r = 1000000;
    int ans = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        string res = ask(mid);
        if (res == "<") {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }

    cout << "! " << ans << endl;
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
