#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin>> n ;
    int a[n] ;
    for ( int i = 0 ; i < n ; i++ )
    {
        cin>> a[i];
    }
    for ( int i = 0 ; i < n-1 ; i++ )
    {
        int j = i+1;
        int k = i ;
        while ( j < n )
        {
            if ( a[k] > a[j])
            {
                k = j ;
            }
            j++;
        }
        swap( a[i] , a[k]);
    }
    for ( int i = 0 ; i < n ; i++ )
    {
        cout << a[i] << " ";
    }
    cout << '\n';


    return 0 ;
}
