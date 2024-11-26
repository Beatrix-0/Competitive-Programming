// Problem link : https://atcoder.jp/contests/abc374/tasks/abc374_c?lang=en

Code 01 :
This code is not correct its made only for simulate how dp state work { 3 state in dp }
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int w[N], dp[N][100005][100005], n;

int yo(int ind, int group_A_cost, int group_B_cost)
{
    if (ind == n)
    {
        return max(group_A_cost, group_B_cost);
    }
    if (dp[ind][group_A_cost][group_B_cost] != -1)
        return dp[ind][group_A_cost][group_B_cost];

    int take_in_A = yo(ind + 1, group_A_cost + w[ind], group_B_cost);
    int take_in_B = yo(ind + 1, group_A_cost, group_B_cost + w[ind]);

    return dp[ind][group_A_cost][group_B_cost] = min(take_in_A, take_in_B);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << yo(0, 0, 0) << '\n';

    return 0;
}


Code 02 :
This code is not correct its made only for simulate how dp state work { reduce 3 state in dp into 2 state }
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int w[N], dp[N][200000];
int n;
int tot_sum = 0;

signed yo(int ind, int group_A_cost)
{
    if (ind == n)
    {
        int group_B_cost = tot_sum - group_A_cost;
        return max(group_A_cost, group_B_cost);
    }

    if (dp[ind][group_A_cost] != -1)
        return dp[ind][group_A_cost];

    int take_in_A = yo(ind + 1, group_A_cost + w[ind]);
    int not_take_in_A = yo(ind + 1, group_A_cost);

    return dp[ind][group_A_cost] = min(take_in_A, not_take_in_A);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        tot_sum += w[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << yo(0, 0) << '\n';

    return 0;
}

Code 03 ( Correct Sloution ):

#include<bits/stdc++.h>
using namespace std ;
#define int long long 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin>> n ;
    vector < int > v(n);
    int tot_sum = 0 ;
    for ( int i = 0 ; i < n ; i++ )
    {
        cin>> v[i];
        tot_sum += v[i];
    }

    int sz = ( 1 << n );
    int ans = INT_MAX ;
    for ( int i = 0 ; i < sz ; i++ )
    {
        int k = i , sum_A = 0 ;
        for ( int j = 0 ; j < n ; j++ )
        {
            if ( (1<<j)&k )
            {
                sum_A += v[j];
            }
        }
        int sum_B = tot_sum - sum_A;
        ans = min  ( ans  , max (sum_A , sum_B ));
    }

    cout << ans << '\n';
    return 0 ;
}


