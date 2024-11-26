#include <bits/stdc++.h> // finding the subsequence by recursion
using namespace std;

void subsequence ( int ind , vector<int>&ans , int arr[] , int n  )

{
    if ( ind == n )
    {
        for ( auto it : ans )
        {
            cout << it << " ";
        }
        if ( ans.size() == 0 )
        {
            cout << "{}" ;
        }
        cout << '\n';
        return ;
    }

    ans.push_back(arr[ind]);

    subsequence ( ind + 1 , ans , arr , n ); // take the last index

    ans.pop_back();

    subsequence ( ind + 1 , ans , arr , n ); // Not take the last index


}

int main()
{
   int n;
   cin>>n ;
   int arr[n];
   for ( int i = 0 ; i< n ; i++ )
   {
       cin>> arr[i];
   }
   vector<int>ans;

   subsequence( 0 , ans , arr , n );

    return 0;
}

// Video link : https://youtu.be/AxNNVECce8c?feature=shared