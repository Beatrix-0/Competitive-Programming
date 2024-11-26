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
    };

    pokemon a , b ;

    a.name = "Siam";
    a.ability = 100 ;

    b = a ;
    cout << b.name << " " << b.ability << '\n';


    return 0 ;
}

