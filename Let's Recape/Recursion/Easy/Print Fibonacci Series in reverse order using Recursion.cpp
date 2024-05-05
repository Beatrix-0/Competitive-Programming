#include<bits/stdc++.h>
using namespace std ;

void solve ( int n , int a , int b )
{
    if ( n > 0 )
    {
        solve ( n-1 , b , a+b );

        cout << a << " ";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin>> n ;

    solve ( n , 0 , 1 );

    return 0 ;
}
