#include<bits/stdc++.h>
using namespace std ;

int solve_mx ( vector <int>&v , int n )
{
    if ( n == 1 )
    {
        return v[n-1];
    }

    return max( v[n-1] , solve_mx( v , n-1 ) );


}

int solve_mn ( vector <int>&v , int n )
{
    if ( n == 1 )
    {
        return v[n-1];
    }

    return min( v[n-1] , solve_mx( v , n-1 ) );


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin>> n ;
    vector < int > v(n);
    for ( int i = 0 ; i < n ; i++ )
    {
        cin>> v[i];
    }

    int mx = solve_mx ( v , n );
    int mn = solve_mn ( v , n );

    cout << mx << " " << mn <<  '\n';


    return 0 ;
}
