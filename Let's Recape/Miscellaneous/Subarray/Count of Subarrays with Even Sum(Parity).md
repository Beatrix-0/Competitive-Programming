**Main idea :** if need 0 as even count , then convert 0 to 1 and 1 to 0 , then calulate for 1 , that will be counted of 0 in the end.

```cpp
#include<bits/stdc++.h>
using namespace std ;

#define int long long
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n ;
    string s ; cin >> s ;
    vector<int> v;
    for ( int i = 0 ; i < n ; i++ ){
        if ( s[i] == '1'){
            v.push_back(0);
        }
        else {
            v.push_back(1);
        }
    }

    vector<int> pref(n);
    pref[0] = v[0];
    for ( int i = 1 ; i < n ; i++ ){
        pref[i] = pref[i-1] + v[i];
    }
    int zero = 0 ; // no of pref that end with even sum ;
    int one = 0 ; // no of pref that end with odd sum ;
    for ( int i = 0 ; i < n ; i++ ){
        if ( pref[i]%2 == 0 ){
            zero++;
        }
        else {
            one++;
        }
    }

    // odd+odd = even
    // even + even = even
    // so all possible combination between them are contributed ;
    // formula : n*(n-1)/2

    zero++; // emply string can also be even
    int ans = (zero*(zero-1)/2) + (one *(one-1)/2);
    cout << ans << '\n';

    return 0 ;
}
```

[Problem(Atcoder)](https://atcoder.jp/contests/abc418/tasks/abc418_d)
