// Memoization Code --> In this code i have to use recursion function [ Top to Bottom ]

#include <bits/stdc++.h>
using namespace std;

int ans(int ind, int k, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int mn_steps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if ((ind - j) >= 0)
        {
            int jump = ans(ind - j, k, heights, dp) + abs(heights[ind] - heights[ind - j]);
            mn_steps = min(mn_steps, jump);
        }
    }

    return dp[ind] = mn_steps ;
}

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    vector<int> dp(n + 1, -1);

    int res = ans(n - 1, k, heights, dp);

    cout << res << '\n';


    return 0;
}


// Tabulation code -- > There is no need to use recursion [Bottom to Top ]

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    vector<int> dp(n + 1, 0);

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int mn_steps = INT_MAX;
        int jump;

        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                mn_steps = min(mn_steps, jump);
            }
        }

        dp[i] = mn_steps;
    }

    cout << dp[n - 1] << '\n';
    return 0;
}

/*
 Problem link : https://atcoder.jp/contests/dp/tasks/dp_b?lang=en
Video link : https://youtu.be/Kmh3rhyEtB8?feature=shared
Title : DP 4. Frog Jump with K Distance | Lecture 3 Follow Up Question
*/
