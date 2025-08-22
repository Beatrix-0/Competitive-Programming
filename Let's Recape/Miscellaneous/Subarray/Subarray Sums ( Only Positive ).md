```cpp
#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

        int n , x ;
        cin >> n >> x ;

        vector < int >v(n);
        for( int i = 0 ; i < n ; i++ ) {
            cin>> v[i];
        }
        map< int , int > mp;
        mp[0] = 1 ;
        int sum = 0 , cnt = 0;
        for ( int i = 0 ; i < n ; i++ ) {
            sum += v[i];
            if ( mp.find(sum-x) != mp.end()) {
                cnt += mp[sum-x];
            }
            mp[sum]++;
        }
        cout << cnt << '\n';

    return 0;
}

```
