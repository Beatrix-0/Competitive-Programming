# Expand Around Possible Centers

Mainly used in palindrom type problem </br>

## Resources

1. [Blog](https://osgoodgunawan.medium.com/expand-around-possible-centers-11bf48127d59)

## Practice Problem

2. [Q3. Longest Almost-Palindromic Substring](https://leetcode.com/contest/weekly-contest-489/problems/longest-almost-palindromic-substring/)

```cpp
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "trace.cpp"
#else
#define dbg(...)
#endif

string s ;
int n ;

int yo ( int l , int r ){
    while ( l >= 0 && r < n ){
        if ( s[l] == s[r] ){
            l--;
            r++;
        }
        else{
            int l1 = l-1 , r1 = r;
            while( l1 >= 0 && r1 < n && s[l1] == s[r1]){
                l1--;
                r1++;
            }
            int l2 = l , r2 = r+1;
            while( l2 >= 0 && r2 < n && s[l2] == s[r2]){
                l2--;
                r2++;
            }
            return max( r1-l1-1 , r2-l2-1);
        }
    }
    if ( l <= 0 && r >= n ) return r - l -1;
    else return r - l;

}

void solve() {
    cin >> n ;
    cin >> s ;
    int mxLen = 0 ;
    if ( n > 1 ){
        for ( int i = 0 ; i < n ; i++ ){
            int x = yo(i,i); // odd
            int y = yo(i,i+1); // even
            int len = max ( x , y );
            mxLen = max (mxLen , len);
        }
    }
    cout << mxLen << '\n';
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
