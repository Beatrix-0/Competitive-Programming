// Memoization Code --> In this code i have to use recursion function [ Top to Bottom ]

#include <bits/stdc++.h>
using namespace std;

int ans(int ind, vector<int> &heights, vector<int> &dp)
{
    if (ind == 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int left = ans(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = ans(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    }

    return dp[ind] = min(left, right);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
        {
            
            cin >> heights[i]; 
        }
        vector<int> dp(n + 1, -1);

        int res = ans(n - 1, heights, dp);

        cout << res << '\n';
    }

    return 0;
}


// Tabulation code -- > There is no need to use recursion [Bottom to Top ]

#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }
        vector<int> dp(n, 0);

        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
            int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int right = INT_MAX;
            if (i > 1)
            {
                right = dp[i - 2] + abs(heights[i] - heights[i - 2]); 
            }

            dp[i] = min(left, right);
        }

        cout << dp[n - 1] << '\n';
    }

    return 0;
}


// Space optimization code -- > There is no need to use recursion

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> heights[i];
        }

        int prev_1 = 0 ;
        int prev_2 = 0 ;

        for ( int i = 1 ; i< n ; i++)
        {
            int left = prev_1 + abs (heights[i] - heights[i-1] );
            int right = INT_MAX ;
            if ( i > 1 )
            {
                right = prev_2 + abs ( heights[i] - heights[i-2]);
            }
            int cur = min ( left , right );

            prev_2 = prev_1 ;
            prev_1 = cur ;

        }

        cout << prev_1 << '\n';


    }

    return 0;
}


Problem link : https://rb.gy/ue0xgc
Video link : https://youtu.be/EgG3jsGoPvQ?feature=shared
Title : DP 3. Frog Jump | Dynamic Programming | Learn to write 1D DP