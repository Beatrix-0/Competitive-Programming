#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, total_w;
    cin >> n >> total_w;

    vector<int> item(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> item[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    // [fraction, {item, weight}]
    vector<pair<double, pair<int, int>>> pr;
    for (int i = 0; i < n; i++)
    {
        pr.push_back({item[i] * 1.0 / weight[i], {item[i], weight[i]}});
    }

    sort(pr.rbegin(), pr.rend());
    double mx = 0.0;
    for (auto it : pr)
    {
        if (it.second.second <= total_w)
        {
            mx += it.second.first;
            total_w -= it.second.second;
        }
        else
        {
            mx += it.first * total_w;
            break;
        }
    }

    cout << fixed << setprecision(6) << mx << '\n';

    return 0;
}

/* 
3 50
60 100 120
10 20 30
*/
