#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ;
    cin>> t ;
    while(t--)
    {
        int n ;
        cin>> n ;
        vector< pair < int, int >> pr ;
        int mx_l = -1, mn_r = INT_MAX;
        for ( int i = 0 ; i < n ; i++ )
        {
            int l, r ;
            cin>> l >>  r ;
            pr.push_back({ l, r });
            mx_l = max( mx_l, l );
            mn_r = min( mn_r, r );

        }

        if ( mx_l <= mn_r )
        {
            cout << "There is a common point exist where every element can intersect" << '\n';
        }
        else
        {
            cout << "Not all element can intersect in a common point" << '\n';
        }
    }


    return 0 ;
}

/*
2
2
1 5
4 7
2
1 3
5 9
*/

// https://youtu.be/daLeQLFtLLI?si=_YguwEFnNfz0yCKW