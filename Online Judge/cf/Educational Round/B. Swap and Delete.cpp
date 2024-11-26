#include<bits/stdc++.h> // Logic + Code 
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin>> s ;
        int cnt_0 = 0 ;
        int cnt_1 = 0 ;

        for ( int i = 0 ; i< s.size() ; i++ )
        {
            if ( s[i] == '0')
            {
                cnt_0++;
            }
            else
            {
                cnt_1++;
            }
        }


        for ( int i = 0 ; i< s.size() ; i++ )
        {
            if ( s[i] == '0')
            {

                if ( cnt_1 > 0 )
                {
                    cnt_1--;
                }
                else
                {
                    break;
                }

            }
            else
            {
                if ( cnt_0 > 0 )
                {
                    cnt_0--;
                }
                else
                {
                    break;
                }

            }
        }

        int ans = abs ( cnt_0 - cnt_1 );

        cout << ans << '\n';
    }
    return 0;
}

// video : https://youtu.be/hfrK3swrtU0?feature=shared

