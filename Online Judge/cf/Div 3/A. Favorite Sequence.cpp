#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int t ;
    cin>> t ;
    while(t--)
    {
        int n ; cin>>n ;
        vector <int>v(n);
        for ( int i = 0 ; i< n ; i++ )
        {
            cin>> v[i];
        }
        vector <int> ans ;

        int i = 0 ;
        int j = n-1 ;
        while ( i < j )
        {
            ans.push_back(v[i]);
            ans.push_back(v[j]);

            i++;
            j--;

        }
        if ( n%2 == 1 ) // odd thakle extra ekta alada input korte hobe 
        {
            ans.push_back(v[i]);
        }


        for ( auto it : ans )
        {
            cout << it << " ";
        }
        cout << '\n';
    }


    return 0 ;
}

//Topic : two pointer 