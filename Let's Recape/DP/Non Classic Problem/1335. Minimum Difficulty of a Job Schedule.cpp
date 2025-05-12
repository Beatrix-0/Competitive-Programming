// Problem : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/


Code Leetcode Formate : 
class Solution {
public:
    static const int mx = 1e3+123
    int dp[mx][mx];

    int yo(vector<int>& v, int n, int ind, int d) {
        if (d == 1) {
            int x = INT_MIN;
            for (int i = ind; i < n; i++) {
                x = max(x, v[i]);
            }
            return x;
        }

        if (dp[ind][d] != -1) return dp[ind][d];

        int mx_job = INT_MIN;
        int res = INT_MAX;

        for (int i = ind; i <= n - d; i++) {
            mx_job = max(mx_job, v[i]);
            res = min(res, mx_job + yo(v, n, i + 1, d - 1));
        }

        return dp[ind][d] = res;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        memset(dp, -1, sizeof(dp));
        return yo(jobDifficulty, n, 0, d);
    }
};



Code Codeforces Formate: 
#include<bits/stdc++.h>
using namespace std ;

const int mx = 1e3+123;
int dp[mx][mx];
int n , dis ;
int v[mx];

int yo ( int ind , int d ){

    if ( d == 1 ){
        int x = INT_MIN;
        for ( int i = ind ; i < n ; i++ ){
            x = max( x , v[i]);
        }
        return x ;
    }

    if ( dp[ind][d] != -1 ) return dp[ind][d];

    int mx = INT_MIN;
    int res = INT_MAX;

    for ( int i = ind ; i <= n - d ; i++ ){
        mx = max( mx , v[i]);
        res = min( res , mx + yo(i+1 , d-1));
    }
    return dp[ind][d] = res ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> dis ;
    memset(dp , -1 , sizeof(dp));
    for ( int i = 0 ; i < n ; i++ ){
        cin >> v[i];
    }

    if( n < dis ){
        cout << -1 << '\n';
    }
    else {
        cout << yo(0 , dis );
    }
    
    return 0 ;
}
