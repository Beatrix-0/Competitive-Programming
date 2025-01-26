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
        int n, k, m ;
        cin>> n >> k >> m ;
        vector < int > v;
        for( int i = 0 ; i < n ; i++ )
        {
            v.push_back(i+1);
        }
        vector<vector<int>>tmp;
        tmp.push_back(v);
        k--;
        while ( next_permutation(v.begin(), v.end()) && k--)
        {
            reverse(v.begin(),v.end());
            tmp.push_back(v);

        }
        /* for ( int i = 0 ; i < tmp.size() ; i++ )
          {
              for ( int j = 0 ; j < n ; j++ )
              {
                  cout << tmp[i][j] << " ";
              }
              cout << '\n';
          }
          cout << '\n';
          cout << tmp.size() << '\n';
          cout << tmp[0][0] << " " << tmp[0][1] << " " << tmp[0][2] << '\n';
          cout << tmp[1][0] << " " << tmp[1][1] << " " << tmp[1][2] << '\n';
          */

        int sum = 0 ;
        for ( int j = 0 ; j < m ; j++ )
        {
            sum += tmp[tmp.size()-1][j];
            //cout << tmp[tmp.size()-1][j] << " " ;
        }
        cout << sum << '\n';
    }


    return 0 ;
}
