#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n , m ;
    cin>> n >> m ;
    vector <vector<pair <int , int >>> guest(n);
    for ( int i = 0 ; i < n ; i++ )
    {
        int o ; cin>> o ;
        map < int , int > mp;
        for ( int j = 0 ; j < o ; j++ )
        {
            int iteam , quantity;
            cin>> iteam >> quantity;
            mp[iteam] += quantity ;
        }
        for ( auto it : mp )
        {
            guest[i].push_back(it);
        }
    }

    vector<int > available(m+1);
    for ( int i = 1 ; i <= m ; i++ )
    {
        cin>> available[i];
    }

    int ans = 0 ;
    for ( int mask = 0 ; mask < ( 1 << n) ; mask++ )
    {
        auto tmp = available;
        int cnt = 0 ;
        bool ok = true ;
        for ( int i = 0 ; i < n ; i++ )
        {
            if( mask & (1 << i ))
            {
                for ( auto [ type , quantity] : guest[i])
                {
                    if ( tmp[type] < quantity )
                    {
                        ok = false ;
                        break ;
                    }
                }
                if (ok)
                {
                    cnt++;
                    for ( auto [ type , quantity] : guest[i])
                    {
                        tmp[type] -= quantity;
                    }
                }
                else
                {
                    break ;
                }
            }
            if (ok)
            {
                ans = max ( ans , cnt );
            }

        }

    }
    cout << ans << '\n';


    return 0 ;
}
