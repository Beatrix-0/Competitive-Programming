#include<bits/stdc++.h>
using namespace std ;
#define int long long int

const int N = 1e8;
int n , dp[N];
int mn_step( int i )
{
    if ( i == 0 ) return 1 ;
    if ( i == 1 ) return 1 ;
    if ( dp[i] != -1 ) return dp[i];
    int ans = mn_step( i-1 ) + mn_step(i-2); // sum of ways
    return dp[i] = ans ;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ;  cin>> t;
    while ( t-- )
    {
       cin >> n ;
       memset( dp , -1 , sizeof(dp));
       cout << mn_step(n) << '\n';
    }

    return 0 ;
}

/*
Video : https://youtu.be/mLfjzJsN8us?si=svtjYAU-sjonkqHN
Problem : https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos 
*/