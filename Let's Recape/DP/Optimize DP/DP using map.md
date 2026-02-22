## DP Using Map

Problem : [Q4. Count Sequences to K](https://leetcode.com/contest/weekly-contest-490/problems/count-sequences-to-k/description/)

```cpp
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "trace.cpp"
#else
#define dbg(...)
#endif
#define int long long

map<pair<int,pair<int,int>>, int>dp;
vector<int>v;
int n , k ;

pair<int,int>frac( int x , int y){
    int gc = __gcd( x , y );
    x /= gc ;
    y /= gc ;
    return{x , y};
}

int yo( int ind , const pair<int,int>&val ){
    if (ind == n ){
        return (val.first == k && val.second == 1 );
    }

    auto key = make_pair(ind , val);
    if(dp.count(key)) return dp[key];

    int ans = 0 ;
    int add = v[ind];

    ans += yo(ind+1 , frac(val.first*add, val.second) );
    ans += yo(ind+1 , frac(val.first, val.second*add) );
    ans += yo(ind+1 , val);

    return dp[key] = ans;
}

void solve() {
    cin >> n >> k ;
    v.resize(n);
    for ( int i = 0 ; i < n ; i++ ){
        cin >> v[i];
    }
    int way = yo(0 , {1,1} );
    cout << way << '\n';
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
