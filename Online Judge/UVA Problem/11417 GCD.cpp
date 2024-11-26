#include<bits/stdc++.h>
using namespace std ;
#define int long long

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a ;
    }
    else
    {
        return gcd(b, a % b);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        else
        {
            int sum = 0;
            for (int i = 1; i < n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    sum += gcd(i, j);
                }
            }
            cout << sum << '\n';
        }
    }

    return 0;
}
