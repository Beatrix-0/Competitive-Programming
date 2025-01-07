#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 1e5 + 9;

int t[N][18];
int a[N];

void build(int n)
{
    for (int i = 1; i < n; ++i)
    {
        t[i][0] = a[i];
    }
    for (int k = 1; k < 18; ++k)
    {
        for (int i = 1; i + (1 << k) - 1 < n; ++i)
        {
            t[i][k] = __gcd(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int query(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return __gcd(t[l][k], t[r - (1 << k) + 1][k]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t ;
    cin>> t ;
    while ( t-- )
    {
        int n, q ;
        cin >> n >> q ;
        vector<int> v(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            cin >> v[i];
        }

        for (int i = 1; i < n; ++i)
        {
            a[i] = abs(v[i] - v[i + 1]);
        }

        build(n);

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            if (l == r)
            {
                cout << 0 << " " ;
            }
            else
            {
                cout << query(l, r - 1) << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}

/// https://codeforces.com/contest/2050/problem/F