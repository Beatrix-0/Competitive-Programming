#include<bits/stdc++.h> // Logic 
using namespace std;
#define ll long long

int main()
{
    int t ;
    cin >> t ;
    while ( t-- )
    {
        ll a, b ;
        cin >> a >> b ;

        if ( b == 1 )
        {
            cout << "NO" << '\n';
        }
        else 
        {
            cout << "YES" << '\n';
            cout << a << " " << a * b << " " << a * ( b + 1 ) << '\n';
        }
    }

    return 0;
}

// Check Tuotorial 