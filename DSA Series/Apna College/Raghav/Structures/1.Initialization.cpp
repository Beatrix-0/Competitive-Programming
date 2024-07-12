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

    pokemon x ;
    x.name = "Pikachu";
    x.ability = 100;
    x.position = 'A';

    cout <<  x.name << " " <<  x.ability << " " <<  x.position << '\n';


    return 0 ;
}

