#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    struct pokemon
    {
        string name ;
        int ability ;
        char position ;
    };

    // manually
   /* pokemon arr[2];

    arr[0].name = "Siam";
    arr[0].ability = 100;
    arr[0].position = 'A';

    arr[1].name = "Fahim";
    arr[1].ability = 200;
    arr[1].position = 'B';

    for ( int i = 0 ; i < 2 ; i++ )
    {
        cout << arr[i].name << " " << arr[i].ability << " " << arr[i].position << '\n';
    } */

    // User input

    int n ; cin>> n ;
    pokemon arr[n];

    for ( int i = 0 ; i < n ; i++ )
    {
        cin>> arr[i].name;
        cin>> arr[i].ability;
        cin>> arr[i].position;
    }

    for ( int i = 0 ; i < n ; i++ )
    {
        cout << arr[i].name << " " << arr[i].ability << " " << arr[i].position << '\n';
    }

    return 0 ;
}

/* input
2
Siam 100 A
Fahim 200 B
*/

