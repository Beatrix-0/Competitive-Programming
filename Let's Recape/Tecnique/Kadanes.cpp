// Kadane's Algorithm | Maximum Subarray Sum | TC = O(n)
// Code :
#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin>> n ;
    vector < int > v(n);
    for ( int i = 0 ; i < n ; i++ )
    {
        cin>> v[i];
    }

    // for sum
    int ans = INT_MIN;
    int sum = 0 ;

    // for index
    int tmp_st , st_ind = -1 , end_ind = -1 ;

    for ( int i = 0 ; i< n ; i++ )
    {
        if ( sum == 0 )
        {
            tmp_st = i ;
        }
        sum = sum + v[i];
        if ( sum > ans )
        {
           ans = sum ;
           st_ind = tmp_st;
           end_ind = i ;        
        }
        if ( sum < 0 )
        {
            sum = 0 ;
        }
    } 

    cout << "Maximum Subarray sum : " << ans << '\n';
    cout << "Maximum Subarray length is :" << st_ind+1 << " to " << end_ind+1 << '\n';

    return 0 ;
}

Problem :
1. https://leetcode.com/problems/maximum-subarray/submissions/1205060391/
2. https://cses.fi/problemset/result/8753617/

--------------------------------------------------------------------------------------------------------------------