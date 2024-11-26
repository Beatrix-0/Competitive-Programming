#include<bits/stdc++.h> // Logic + Code 
using namespace std ;
int main()
{
    int t ;
    cin>> t ;
    while ( t-- )
    {
        int n , k ;
        cin>> n>> k;

        int a[n] , b[n];

        for ( int i = 0 ; i< n ; i++ )
        {
            cin>> a[i];
        }
        for ( int i = 0 ; i< n ; i++ )
        {
            cin>> b[i];
        }
        int array_sum = 0 , max_experience = 0 , ans = 0 ;

        for ( int i = 0 ; i< min( n , k ) ; i++ )
        {
            array_sum = array_sum + a[i];
            max_experience = max ( max_experience , b[i] );
            ans = max ( ans , ans + array_sum + ( (k - i) - 1 )*max_experience ); // ( k- i) extra koto k ache seta ber kore , extra -1 dewar karon one based index tai

        }

        cout << ans << '\n';
    }


    return 0;
}

/*
Video : https://youtu.be/wzkRP_teDqs?feature=shared
Note : Use notebook and pen for better understand the code 
*/