// Problem : https://www.spoj.com/problems/THRBL/

#include<bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 9;

int t[N][18], a[N];
void build(int n)
{
    for(int i = 1; i <= n; ++i) t[i][0] = a[i];
    for(int k = 1; k < 18; ++k)
    {
        for(int i = 1; i + (1 << k) - 1 <= n; ++i)
        {
            t[i][k] = max(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int query(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return max(t[l][k], t[r - (1 << k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q ;
    cin>> n >> q ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        cin>> a[i];
    }

    build(n);

    int cnt = 0 ;
    while ( q-- )
    {
        int l, r ;
        cin>> l >> r ;
        if ( l > r ) swap ( l , r );
        if ( abs(l-r)<= 1 ) cnt++;
        else
        {
            int mx = query( l+1 , r-1 ) ;
            if( mx <= a[l] )
            {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';


    return 0 ;
}
