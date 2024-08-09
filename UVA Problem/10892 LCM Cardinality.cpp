#include <bits/stdc++.h>
using namespace std;
#define int long long

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

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

vector<int> v; // devisors

void divisor(int n)
{
    v.clear();
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int x = i;
            int y = n / i;

            v.push_back(x);
            if (x != y) v.push_back(y);
        }
    }
}

signed main()
{
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
            divisor(n);
            sort(v.begin(), v.end());

            int cnt = 0;
            for (int i = 0; i < v.size(); i++)
            {
                for (int j = i; j < v.size(); j++)
                {
                    if (lcm(v[i], v[j]) == n)
                    {
                        cnt++;
                    }
                }
            }
            cout << n << " " << cnt << '\n';
        }
    }

    return 0;
}
