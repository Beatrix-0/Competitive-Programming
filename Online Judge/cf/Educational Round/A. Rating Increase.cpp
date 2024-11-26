#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
 
    while (t--)
    {
        string s;
        cin >> s;
        string x = s.substr(0, 1);
        string y = "";
        int ind = 1;
 
        bool chk = false;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                x = x + s[i];
                ind = i + 1; 
                if (i == s.size() - 1)
                {
                    chk = true;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (chk)
        {
            cout << -1 << '\n';
        }
        else
        {
            for (int i = ind; i < s.size(); i++)
            {
                y = y + s[i];
            }
 
            int a = stoi(x);
            int b = stoi(y);
 
            if (x[0] != '0' && y[0] != '0' && a < b)
            {
                cout << a << ' ' << b << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}

// Problem link : https://codeforces.com/contest/1913/problem/A