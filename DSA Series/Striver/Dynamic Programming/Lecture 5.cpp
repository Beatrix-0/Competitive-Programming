// Memoization Code --> In this code i have to use recursion function [ Top to Bottom ]

#include <bits/stdc++.h>
using namespace std;

int max_sum (int ind, vector<int>& num, vector<int>& dp)
{
    if (ind == 0)
    {
        return num[0];
    }

    if (ind < 0)
    {
        return 0;
    }

    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int pick = num[ind] + max_sum (ind - 2, num, dp);
    int not_pick = 0 + max_sum (ind -1 , num, dp);

    return dp[ind] = max(pick, not_pick);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> num(n);
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }

        vector<int> dp(n, -1); // Initialize dp with -1

        int res = max_sum (n - 1, num, dp); // n-1 mane last index theke kaj korbo

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
        vector<int> num(n);
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }

        vector<int> dp(n, 0);

         dp[0] = num[0];

         for ( int i = 1 ; i < n ; i++ )
         {
             int pick = num[i];
             if ( i > 1  )
             {
                 pick = pick + dp[i - 2 ];
             }
             int not_pick = 0 + dp[i-1];

             dp[i] = max ( pick , not_pick );
         }
         cout << dp[n-1] << '\n';
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
        vector<int> num(n);
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }

        vector<int> dp(n, 0);

        int  prev_1 = num[0];
        int  prev_2 = 0 ;
        int cur;

         for ( int i = 1 ; i < n ; i++ )
         {
             int pick = num[i];
             if ( i > 1  )
             {
                 pick = pick + prev_2 ;
             }
             int not_pick = 0 + prev_1;

             cur = max ( pick , not_pick );
             prev_2 = prev_1 ;
             prev_1 = cur ;

         }

         cout << prev_1 << '\n';

    }

    return 0;
}


/*
Problem link : https://shorturl.at/uDHNP
Video link : https://youtu.be/GrMBfJNk_NY?feature=shared
Title : DP 5. Maximum Sum of Non-Adjacent Elements | House Robber | 1-D | DP on Subsequences
*/