#include <bits/stdc++.h>
using namespace std;

struct pokemon
{
    string name;
    int hp;
};

void change (pokemon x)
{
    cout << x.name << " " << x.hp << '\n';
}

void print(pokemon x)
{
    x. name = "Mewtwo";
    x.hp = 200 ;
    cout << "Print in void func " << x. name << " " << x.hp << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pokemon x;
    x.name = "Pikachu";
    x.hp = 100;

    change(x);
    cout << "Print in main func " << x. name << " " << x.hp << '\n';
    // for pass by value function copy a new struct by his own ... and done all operation
    // in his function

    print(x);


    return 0;
}
