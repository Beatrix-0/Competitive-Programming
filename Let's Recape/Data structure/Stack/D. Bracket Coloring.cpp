// Problem : https://codeforces.com/contest/1837/problem/D
#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ;
    cin>> t;
    while ( t-- )
    {
        int n ;
        cin>> n ;
        string s ;
        cin>> s ;
        stack<char>box1, box2 ;

        if( n % 2 )
        {
            cout << -1 << '\n';
            continue ;
        }

        vector < int >ans ;
        int col1 = 0, col2 = 0 ;
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( s[i] =='(')
            {
                if (!box2.empty() && box2.top()== ')')
                {
                    box2.pop();
                    ans.push_back(2);
                    col1 = 1 ;
                }
                else
                {
                    box1.push('(');
                    ans.push_back(1);
                    col2 = 1;
                }
            }
            else if ( s[i] == ')')
            {
                if (!box1.empty() && box1.top()== '(')
                {
                    box1.pop();
                    ans.push_back(1);
                }
                else
                {
                    box2.push(')');
                    ans.push_back(2);
                }
            }
        }

        if ( box1.empty() && box2.empty())
        {
            if ( col1 == 1 && col2 == 1 )
            {
                cout << 2 << '\n';
                for ( int i = 0 ; i< n ; i++ )
                {
                    cout << ans[i] << " ";
                }
                cout << '\n';
            }
            else
            {
                cout << 1 << '\n';
                for ( int i = 0 ; i< n ; i++ )
                {
                    cout << 1 << " ";
                }
                cout << '\n';
            }
        }
        else
        {
            cout << -1 << '\n';
        }
    }


    return 0 ;
}
