#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, a[99], ans;
    string s;
    cin >> t;
    cin.ignore(); 
    while (t--)
    {
        getline(cin, s);
        istringstream is(s);
        n = 0;
        while (is >> a[n])
        {
            n++;
        }
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(ans, gcd(a[i], a[j]));
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
/* Note :
istringstream : https://youtu.be/mqkTUQt4t3g?si=5sl91rGx84wo8Dr9 ( 10:00 min)
*/