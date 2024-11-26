#include<bits/stdc++.h> // Logic + Code 
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k, q ;
        cin>> n >> k >> q ;
        long long  cnt_1 = 0, cnt_2 = 0 ,ans = 0 ;
        vector < long long > v(n);

        for ( int i = 0 ; i< n ; i++ )
        {
            cin>>v[i];
        }

        for ( int i = 0 ; i< n ; i++ )
        {
            if ( v[i] <= q )
            {
                cnt_1++;

                if ( cnt_1 >= k )
                {
                    cnt_2++;
                    ans = ans + cnt_2 ;
                }
            }
            else
            {
                cnt_1 = 0 ;
                cnt_2 = 0 ;
            }


        }

        cout << ans << '\n';


    }

    return 0;
}


/*
**Video : https://youtu.be/mpXvWaCcHWk?feature=shared


*/