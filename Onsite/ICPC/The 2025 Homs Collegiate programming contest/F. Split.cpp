#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc ; cin>> tc ;
    for ( int i = 1 ; i <= tc ; i++ ){
        int n ; cin >> n ;
        vector<int> v(n+1);
        for ( int i = 1 ; i <= n ; i++ ){
            cin >> v[i];
        }
        vector<int>pref(n+1,0) , suff(n+1,0);
        pref[1] = v[1];
        for ( int i = 2 ; i <= n ; i++ ){
            pref[i] = (pref[i-1] & v[i]);
        }
        suff[n] = v[n];
        for ( int i = n-1 ; i >= 1 ; i-- ){
            suff[i] = (suff[i+1]&v[i]);
        }

        int mx = 0 ;
        for ( int i = 1 ; i <= n ; i++ ){
            int a = v[i];
            int b ;
            if ( i == 1 ){
                b = suff[i+1];
            }
            else if( i == n ){
                b = pref[i-1];
            }
            else {
                b = (pref[i-1]&suff[i+1]); 
            }
            mx = max ( mx , abs(a-b));
        }
        cout << mx << '\n';
    }
    
    return 0 ;
}