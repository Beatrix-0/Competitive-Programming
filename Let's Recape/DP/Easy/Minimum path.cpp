#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5;
int step[N];

int solve(int n)
{
    if (n == 1) return 0 ;
    if (step[n] != -1) return step[n];
    int ans = solve(n - 1) + 1;
    if (n % 2 == 0)
    {
        ans = min(ans, solve(n / 2) + 1);
    }
    if (n % 3 == 0)
    {
        ans = min(ans, solve(n / 3) + 1);
    }
    step[n] = ans ;
    return step[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(step, -1, sizeof(step));
    int n;
    cin >> n;
    int x = solve(n);
    cout << x << '\n';

    return 0 ;
}
