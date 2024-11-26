#include<bits/stdc++.h>
using namespace std ;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ;  cin>> t;
    while ( t-- )
    {
       int x ,y  ;
       cin>> x >> y ;
       if ( y % x == 0 )
       {
           cout << x << " " << y << '\n';
       }
       else
       {
           cout << -1 << '\n';
       }
    }


    return 0 ;
}
