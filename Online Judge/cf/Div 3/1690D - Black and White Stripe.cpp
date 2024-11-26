#include<bits/stdc++.h> // Code
using namespace std ;
int main ()
{
    int t;
    cin>> t ;
    while (t-- )
    {
        int n, k ;
        cin>> n >> k ;
        string s ;
        cin>> s ;

        int ans, cnt = 0 ;

        for ( int i = 0 ; i < k ; i++ )
        {
            if ( s[i] == 'W' )
            {
                cnt++;
            }
        }
        ans = cnt ;

        for ( int i = k ; i< n ; i++ )
        {
            if ( s[i] == 'W')
            {
                cnt++;
            }
            if ( s[i-k] == 'W')
            {
                cnt--;
            }

            ans = min ( ans, cnt );
        }

        cout << ans << '\n';
    }


    return 0 ;
}

/*
Topic : Sliding window ***
video : https://www.youtube.com/watch?v=vCTyRBx-luM
*/
