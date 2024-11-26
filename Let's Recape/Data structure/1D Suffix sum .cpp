#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n + 1);
    vector<int> suff(n + 1); 

    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }

    suff[n] = v[n];
    for (int i = n - 1; i >= 1; --i)
    {
        suff[i] = suff[i + 1] + v[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << suff[i] << " ";
    }
    cout << '\n';

    return 0;
}


// Problem : https://codeforces.com/contest/1903/problem/C