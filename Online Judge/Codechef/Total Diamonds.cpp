#include <bits/stdc++.h>
using namespace std;
#define int long long

int update(int x)
{
    int even = 0, odd = 0;
    while (x > 0)
    {
        int a = x % 10;
        if (a % 2)
        {
            odd += a;
        }
        else
        {
            even += a;
        }
        x /= 10;
    }
    return abs(even - odd);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n - 1);

        for (int i = 2; i <= 2 * n; ++i)
        {
            v[i - 2] = update(i);
        }

        vector< int > ind ;
        for ( int i = 0 ; i < n ; i++ )
        {
            ind.push_back(i+1);
        }
        for ( int i = n ; i >= 2 ; i-- )
        {
            ind.push_back(i-1);
        }

        int sum = 0 ;
        for ( int i = 0 ; i < ind.size() ; i++ )
        {
            sum = sum + ind[i]*v[i];
        }
        cout << sum << '\n';

    }

    return 0;
}

// Problem : https://www.codechef.com/DEC17/problems/VK18?tab=statement