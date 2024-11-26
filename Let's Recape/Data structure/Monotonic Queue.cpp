Definition : A monotonic queue is a double-ended queue (deque) used to maintain elements in either increasing or decreasing 
order while supporting efficient operations at both ends (front and back).

Identification :
   Operations: Supports efficient insertion and removal of elements from both the front and back.
   Order Maintenance: Elements are maintained in a monotonic (increasing or decreasing) order.

Typical Problems:
   -> Sliding Window Maximum/Minimum: Find the maximum or minimum value in every subarray of size k as the window slides over the array.   
   -> Range Queries: Compute minimum or maximum values within a specific range of an array.
   -> Dynamic Windows: Problems involving dynamic window sizes where elements expire as new ones are added.

Complexity: 
   Time/Space Complexity: O(n)

Practice Problem :
1. https://leetcode.com/problems/sliding-window-maximum/description/?envType=problem-list-v2&envId=monotonic-queue
   Video - https://youtu.be/29OnjVQ-fk4?si=u1oro0YvZrTCwRIr
   Code - 
   
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && nums[i] > nums[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1)
        {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}

int main()
{
    int n ; cin>> n ;
    int k ; cin>> k ;
    vector < int > v(n);
    for ( int i = 0 ; i < n ; i++ )
    {
        cin>> v[i];
    }
    vector<int> result = maxSlidingWindow(v, k);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << '\n';

    return 0;
}
