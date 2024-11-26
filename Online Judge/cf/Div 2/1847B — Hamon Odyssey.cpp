#include <bits/stdc++.h> // Logic + Code
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0 ; i < n; i++)
        {
            cin >> a[i];

        }

        int chk = a[0];
        for (int i = 0 ; i < n; i++)
        {
            chk = chk & a[i];
        }
        if (chk > 0)
        {
            cout << 1 << '\n';
            continue;
        }
        else
        {
            int chk = a[0];
            int cnt = 0;

            for (int i = 0; i < n; i++)
            {
                chk = chk & a[i];

                if (chk == 0)
                {
                    cnt++;
                    chk = a[i + 1];
                }
            }

            cout << cnt << '\n';
        }
    }

    return 0;
}


/*

Video link : https://youtu.be/GN39QLxT_ek?feature=shared
Logic :
1. poro array r AND operation korbo , jodi 0 theke boro kcho ase tahole 1 tai group
create kora jabe . karon jei value ta peyechi operation er por ota sobceye minimum ,
jodi group kori tahole total sum bere jabe .

2. jodi 0 hoy tahole amra group korte parbo . 1ta group e oi value gola thakbe jegolar bitwise 0 hoy .

*/