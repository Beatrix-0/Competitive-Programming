// Problem : https://leetcode.com/problems/maximum-subarray/description/?envType=problem-list-v2&envId=divide-and-conquer
// Video : https://youtu.be/bJbfO4boNk4?si=7ET3nlgS6aJt7KvG

Leetcode Formate : 
class Solution {
public:
    int maxCrossingSum(vector<int>& nums, int l, int r, int mid) {
        int leftSum = INT_MIN, rightSum = INT_MIN;
        int sum = 0;

        for (int i = mid; i >= l; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        sum = 0;
        for (int i = mid + 1; i <= r; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return leftSum + rightSum;
    }

    int maxSubArrayDivide(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];

        int mid = (l + r) / 2;

        int left = maxSubArrayDivide(nums, l, mid);
        int right = maxSubArrayDivide(nums, mid + 1, r);
        int cross = maxCrossingSum(nums, l, r, mid);

        return max({left, right, cross});
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArrayDivide(nums, 0, nums.size() - 1);
    }
};


Codeforces Formate :
#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

int mxSumCombine(int l, int r, int mid) {
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;

    int sum = 0;
    for (int i = mid; i >= l; i--) {
        sum += v[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum += v[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int mxSum(int l, int r) {
    if (l == r) return v[l];

    int mid = (l + r) / 2;

    int leftMxSubarraySum = mxSum(l, mid);
    int rightMxSubarraySum = mxSum(mid + 1, r);
    int CombineMxSubarraySum = mxSumCombine(l, r, mid);

    return max({leftMxSubarraySum, rightMxSubarraySum, CombineMxSubarraySum});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = mxSum(0, n - 1);
    cout << ans << '\n';

    return 0;
}

// Case :
// 9
// -2 1 -3 4 -1 2 1 -5 4