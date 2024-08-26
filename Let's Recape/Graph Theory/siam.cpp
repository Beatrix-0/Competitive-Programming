#include <bits/stdc++.h>
using namespace std;

bool isSorted(string x)
{
    string tmp = x;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] != tmp[i]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string tmp = s ;
        sort (tmp.begin(), tmp.end());
        if (s == tmp)
        {
            cout << 0 << '\n';
            continue;
        }
        char ch = s[n-1];
        string lx_s = "";
        vector < int > vis(n);
        for ( int i = n-1; i >= 0 ; i--)
        {
            if ( s[i] >= ch )
            {
                lx_s += s[i];
                ch = s[i];
                vis.push_back(i);
            }
        }

        reverse( lx_s.begin(), lx_s.end());
        int cnt = 0 ;
        for ( int i = 0 ; i< lx_s.size() ; i++ )
        {
            if ( lx_s[i] == lx[0]) cnt++;
        }
        for( int i = 0 ; i< lx_s.size() ; i++ )
        {
            s[vec[i]] = lx_s[i];
        }
        if ( isSorted(s))
        {
            cout << lx_s.size()-cnt << '\n';
        }
        else
        {
            cout -1 << '\n';
        }

    }
    return 0;
}
