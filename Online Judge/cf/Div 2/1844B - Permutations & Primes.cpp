#include<bits/stdc++.h> // Logic + Code 
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            cout << 1 << '\n';

        }
        else if (n == 2)
        {
            cout << 1 << " " << 2 << '\n';

        }
        else
        {
            int a[n];
            a[0] = 2;
            a[n - 1] = 3;
            a[n / 2] = 1;

            int j = 4; // 1 2 3 niye newa hoyche tai 4 theke start hobe
            for (int i = 1; i < n - 1; i++)
            {
                if (i == n / 2)
                {
                    continue;
                }
                a[i] = j;
                j++;
            }
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }

    }
    return 0;
}


/*

Video : https://youtu.be/08ih2W0lIA4?feature=shared
Logic :
1. 1 center e thakle 2 samne thakle r 3 sobar ses e thakle i maximum prime number pawa possible
question statement onojaiye ;
