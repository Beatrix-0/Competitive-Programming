#include <bits/stdc++.h> // Editorial + Code 
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        reverse(s.begin(), s.end());
        vector<char> ans;

        for (int i = 0; i < n ; )
        {
            if (s[i] == 'a' || s[i] == 'e')
            {
                ans.push_back(s[i]);
                ans.push_back(s[i + 1]);
                ans.push_back('.');
                i = i + 2;
            }
            else
            {
                ans.push_back(s[i]);
                ans.push_back(s[i + 1]);
                ans.push_back(s[i + 2]);
                ans.push_back('.');
                i = i + 3;
            }
        }

        if ( ans.back() == '.')
        {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());

        for (auto it : ans)
        {
            cout << it;
        }
        cout << '\n';
    }
    return 0;
}