#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int chk = 0;

    while (getline(cin, s))
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '"')
            {
                if (chk % 2 == 0)
                {
                    cout << "``";
                }
                else
                {
                    cout << "''";
                }
                chk++;
            }
            else
            {
                cout << s[i];
            }
        }
        cout << '\n';
    }

    return 0;
}
