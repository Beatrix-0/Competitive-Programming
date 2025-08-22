[Video Tutorial](https://youtu.be/7wYGbV_LsX4?si=jRbfHaAr-YlMjRLC)

```cpp
#include<bits/stdc++.h>
using namespace std ;
#define int long long

int tot_sub_array( vector<int>&v , int n , int k )
{
    map <int, int>mp;
    int cnt = 0 ;
    for ( int r = 0 , l = 0  ; r < n ; r++ ){
        mp[v[r]]++;
        while ( mp.size() > k ){
            if ( mp[v[l]] == 1 ){
                mp.erase(v[l]);
            }
            else{
                mp[v[l]]--;
            }
            l++;
        }
        cnt = cnt + (r-l+1);
    }
    return cnt ;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , k ;
    cin>> n >> k ;
    vector< int > v(n);
    for ( int i = 0 ; i < n ; i++ ){
        cin>> v[i];
    }

    /* Formula for exactly k : (<=k) - (<=k-1) = k
       Formula for atmost k : <=k
    */

    cout << tot_sub_array(v,n,k) << '\n';

    return 0 ;
}
```
