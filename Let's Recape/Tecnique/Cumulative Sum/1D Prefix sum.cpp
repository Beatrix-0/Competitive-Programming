#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n + 1);
    vector<int> prefix(n + 1, 0); 

    for (int i = 1; i <= n; i++ )
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        prefix[i] = prefix[i - 1] + v[i];
    }
    
    for (int i = 1; i <= n; ++i)
    {
        cout << prefix[i] << " ";
    }
    cout << '\n';

    return 0;
}
