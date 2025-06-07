```cpp
// problem : https://codeforces.com/problemset/problem/1741/D

#include<bits/stdc++.h>
using namespace std ;

int ans = 0 ;
vector < int > v;

// top dowm approach recursive way 
// can be done using bottom up ( merge type)
void yo ( int l1 , int r1 , int l2 , int r2 ){
    int leftMx = 0 ;
    for ( int i = l1 ; i <= r1 ; i++ ){
        leftMx = max ( leftMx , v[i]);
    }

    int rightMn = INT_MAX ; 
    for ( int i = l2 ; i <= r2 ; i++ ){
        rightMn = min ( rightMn , v[i]);
    }

    if( leftMx > rightMn ){
        // need swap between left and rigth segment
        int ind = l2 ;
        for ( int i = l1 ; i <= r1 ; i++ ){
            swap( v[i] , v[ind]);
            ind++;
        }
        ans++;
    }

    if ( l1 == r1 ) return ; 

    int mid1 = (l1 + r1)/2;
    int mid2 = (l2 + r2)/2;

    yo ( l1 , mid1 , mid1+1 , r1 ); 
    yo ( l2 , mid2 , mid2+1 , r2 ); 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc ; cin>> tc ;
    for ( int i = 1 ; i <= tc ; i++ ){
        int n ; cin >> n ;
        v.resize(n+1);
        for ( int i = 1 ; i <= n ; i++ ){
            cin >> v[i];
        }

        ans = 0 ;
        vector<int> tmp = v;
        sort(tmp.begin() + 1, tmp.end());

        if ( v == tmp ){
            cout << 0 << '\n';
            continue;
        }

        int mid = (n+1)/2;
        yo(1 , mid , mid+1 , n );
        if( v == tmp ){
            cout << ans << '\n';
        }else {
            cout << -1 << '\n';
        }
    }
    
    return 0 ;
}
```