#include<bits/stdc++.h>
using namespace std;

int rec(vector<int>& v, int n)
{
    if (n == 1)
    {
        return v[0];
    }
    int sum = rec(v, n - 1);
    return sum + v[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int sum = rec(v, n);
    cout << sum << '\n';

    return 0;
}
