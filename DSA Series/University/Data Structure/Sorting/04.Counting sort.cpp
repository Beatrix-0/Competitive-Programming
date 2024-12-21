#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mx = *max_element(a, a + n);
    int cnt[mx + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }

    int ind = 0;
    for (int i = 0; i <= mx; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            a[ind++] = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    return 0;
}
