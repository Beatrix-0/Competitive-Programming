// Problem : https://leetcode.com/problems/perfect-squares/


// Leetcode Formate : 
class Solution {
public:
    int dp[10005][110];

    int yo(int curSum, int pos, const vector<int>& v) {
        if (curSum == 0) return 0;
        if (pos == v.size()) return INT_MAX;
        if (dp[curSum][pos] != -1) return dp[curSum][pos];

        int take = INT_MAX;
        int notake = yo(curSum, pos + 1, v);

        if (curSum >= v[pos]) {
            int add = curSum / v[pos];
            int sub = yo(curSum - v[pos] * add, pos + 1, v);
            if (sub != INT_MAX) {
                take = add + sub;
            }
        }

        return dp[curSum][pos] = min(take, notake);
    }

    int numSquares(int n) {
        vector<int> v;
        for (int i = 1; i * i <= n; ++i)
            v.push_back(i * i);
        reverse(v.begin(), v.end());

        memset(dp, -1, sizeof(dp));
        return yo(n, 0, v);
    }
};


// CF formate :
#include<bits/stdc++.h>
using namespace std;

const int mx = 1e4 + 123;
int dp[mx][110];

int yo(int curSum, int pos, const vector<int>& v) {
    if (curSum == 0) return 0;
    if (pos == v.size()) return INT_MAX;
    if (dp[curSum][pos] != -1) return dp[curSum][pos];

    int take = INT_MAX;
    int notake = yo(curSum, pos + 1, v);

    if (curSum >= v[pos]) {
        int cnt = curSum / v[pos];
        int sub = yo(curSum - v[pos] * cnt, pos + 1, v); // check for remaining 
        if (sub != INT_MAX) {
            take = cnt + sub;
        }
    }

    return dp[curSum][pos] = min(take, notake);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> v;

    for (int x = 1; x * x <= n; x++) {
        v.push_back(x * x);
    }
    reverse(v.begin(), v.end());

    memset(dp, -1, sizeof(dp));
    int mnNeeded = yo(n, 0, v);
    cout << mnNeeded << '\n';
    return 0;
}
