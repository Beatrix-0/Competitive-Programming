#include<bits/stdc++.h> // Logic
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        map<int, int> num ;

        for ( int i = 0 ; i< n-1 ;i++ )
        {
            int x, y;
            cin >> x >> y;
            num[x]++;
            num[y]++;
        }
        int cnt = 0 ;
        for ( auto it : num )
        {
            if ( it.second == 1 )
            {
                cnt++;
            }
        }
        
        // total leaf even hole half hobe ans r odd hole extra 1 add hobe 
        if ( cnt % 2 == 0 )
        {
            cout << cnt/2 << '\n';
        }
        else
        {
            cout << (cnt/2)+1 << '\n';
        }

    }

    return 0;
}