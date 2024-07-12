#include <bits/stdc++.h>
using namespace std;

struct pokemon
{
    string name;
    int ability;
};

void change(pokemon* p)
{
    p->name = "Akbar"; // (*p).name =  "Akbar"
    p->ability = 50;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pokemon pikachu;

    pikachu.name = "Fahim";
    pikachu.ability = 200;

    cout << "Before Change: " << pikachu.name << " " << pikachu.ability << '\n';

    change(&pikachu);

    cout << "After Change: " << pikachu.name << " " << pikachu.ability << '\n';

    return 0;
}

//Note : We only chnage the value outside the main function if we use pass
//by reference in function .... because they change the value in memory adress
//not create another adress in memory
