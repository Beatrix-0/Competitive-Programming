#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    struct pokemon
    {
        string name;
        int hp;
    };

    struct legendary_pokemon
    {
        pokemon x;
        int accuracy;
    };

    struct ultra_legendary_pokemon
    {
        legendary_pokemon xx;
        int strength;
    };

    // pokemon
    pokemon p;
    p.name = "Pikachu";
    p.hp = 97;

    cout << "1st" << '\n';
    cout << p.name << " " << p.hp << '\n';

    // legendary_pokemon
    legendary_pokemon lp;
    lp.x.name = "Lucario";
    lp.accuracy = 99;

    cout << "2nd" << '\n';
    cout << lp.x.name << " " << lp.accuracy << '\n';

    // ultra_legendary_pokemon
    ultra_legendary_pokemon ulp;
    ulp.xx.x.name = "Mewtwo";
    ulp.strength = 100;

    cout << "3rd" << '\n';
    cout << ulp.xx.x.name << " " << ulp.strength << '\n';

    return 0;
}
