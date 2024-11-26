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

    pokemon pikachu;

    pokemon *x = &pikachu;

     pikachu.name = "Fahim" ;
     pikachu.ability = 200;

     cout << "Before pointer : " << pikachu.name << " " <<  pikachu.ability << '\n';

    (*x).name = "Siam";
    (*x).ability = 100 ; // (*x).name == x->name

    cout << "After pointer : " << x->name << " " << x->ability << '\n';



    return 0 ;
}
