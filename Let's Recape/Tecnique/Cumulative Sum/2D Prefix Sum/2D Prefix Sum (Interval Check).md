[Problem](https://codeforces.com/contest/2113/problem/C)

```cpp
#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    for (int i = 1; i <= tc; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        char v[n + 5][m + 5];
        int pref[n + 5][m + 5];
        memset(pref, 0, sizeof(pref));
        int totG = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> v[i][j];
                if (v[i][j] == 'g') {
                    pref[i][j] = 1 + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
                    totG++;
                }
                else {
                    pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
                }
            }
        }

        int mn = INT_MAX;
        for( int i = 1 ; i <= n ; i++ ){
            for ( int j = 1 ; j <= m ; j++ ){
                if( v[i][j] == '.'){
                    // interval
                    int x1 = max(1 , i-k+1);
                    int y1 = max(1 , j-k+1);
                    int x2 = min( n , i+k-1);
                    int y2 = min( m , j+k-1);
                    int val =  pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
                    mn = min( mn , val );
                }
            }
        }
        if (mn == INT_MAX){
            cout << 0 << '\n';
        }
        else {
            cout << totG - mn << '\n';
        }
    }

    return 0;
}
```
