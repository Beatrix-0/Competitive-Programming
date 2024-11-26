#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    typedef struct pokemon
    {
        string name ;
        int hp ;
        char level;

    } pokemon ;

    pokemon pikachu ;

    pikachu.name = "poke";
    pikachu.hp = 100;
    pikachu.level = 'A';
    pokemon* a = &pikachu;

    cout << "Adress :" <<  &pikachu.name << " " << &pikachu.hp << " " << &pikachu.level << '\n';
    cout << "Value :" << a->name << " " << a->hp << " " << a->level << '\n';

    cout << &pikachu << " " << &pikachu.name << '\n'; // same adress because returning only 1st
                                                       // index adress


    return 0 ;
}

