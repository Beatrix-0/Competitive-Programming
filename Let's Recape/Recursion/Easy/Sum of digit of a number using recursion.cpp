#include<bits/stdc++.h>
using namespace std ;

int solve ( string s , int ind )
{
     if ( s[ind] == '\0')
     {
         return 0 ;
     }

     return (s[ind] - '0' ) + solve ( s , ind + 1 );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s ; cin>> s ;
    int sum = solve ( s , 0 );

    cout << sum << '\n';


    return 0 ;
}
