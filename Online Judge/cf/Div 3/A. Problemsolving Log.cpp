#include<bits/stdc++.h> // Logic 
using namespace std ;
int main()
{
    int t ;
    cin>> t ;
    while ( t-- )
    {
        int n;
        cin>>n;
        string s ;
        cin>> s ;

        map < char , int > freq ;
        for ( auto it : s )
        {
            freq[it]++;
        }

        int ans = 0 ;
        for ( auto it : freq )
        {
            if ( it.second >= it.first - 64 ) // -64 diye bujacche problem ta solve korte tar koto somoy lagbe
                ans++;
        }

        cout << ans << '\n';

    }


    return 0 ;
}
