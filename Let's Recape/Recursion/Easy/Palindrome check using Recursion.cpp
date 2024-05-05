#include<bits/stdc++.h>
using namespace std;

string solve(string s, int n)
{
    if (n == 0)
    {
        return "";
    }

    return s[n - 1] + solve(s, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string d = solve(s, s.size());
    if ( s == d ) cout << "Palindrome" << '\n';
    else cout << "Not Palindrome" << '\n';

    return 0;
}
