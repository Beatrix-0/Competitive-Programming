#include <bits/stdc++.h>
using namespace std;

int main()
{
    string tmp ;
    map<string, string> mp;

    while (getline(cin, tmp) && !tmp.empty()) // limitation na thakle while diye user input nite hoy 
    {
        string a, b;
        stringstream ss(tmp);
        
        ss >> a >> b;
        mp[b] = a ;
    }

    string w ;
    while (cin >> w )
    {
        if (mp.find(w) != mp.end())
        {
            cout << mp[w] << endl;
        }
        else
        {
            cout << "eh" << endl;
        }
    }

    return 0;
}
