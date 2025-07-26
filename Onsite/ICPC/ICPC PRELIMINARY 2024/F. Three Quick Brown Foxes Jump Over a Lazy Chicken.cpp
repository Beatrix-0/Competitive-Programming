#include<bits/stdc++.h>
using namespace std ;

#define int long long 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc ; cin>> tc ;
    for ( int i = 1 ; i <= tc ; i++ ){
        int x , y , z;
        cin >> x >> y >> z;

        int s = (x+y+z)/2;
        int up = s*(s-x)*(s-y)*(s-z);
        int down = s*s;
        int gc = __gcd(up , down);

        int numerator = up/gc;
        int denominator = down/gc;

        cout << numerator << "/" << denominator << '\n';
    }
    
    return 0 ;
}
