#include<bits/stdc++.h>
using namespace std ;

int solve ( int n )
{
    if ( n > 0 )
    {
        return ( n%2 ) + solve( n/2 );
    }
    else
    {
        return n ;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin >> n ;

    int ans = solve ( n );
    cout << ans << '\n';


    return 0 ;
}
