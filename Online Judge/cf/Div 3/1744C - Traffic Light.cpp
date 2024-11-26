#include <bits/stdc++.h> // Editorial 
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        char k;
        cin >> n >> k;
        string s;
        cin >> s;
        string x = s + s; // Cyclic remove korar jonno duibar likha hoyeche

        int ans = INT_MIN;
        int last_g = -1;

        for (int i = x.size() - 1; i >= 0; i--)
        {
            if (x[i] == 'g')
            {
                last_g = i;
            }
            else if (x[i] == k) // g er sathe k er distance check kortechi
            {
                ans = max(ans, last_g - i);
            }
        }

        if ( ans == INT_MIN )
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << ans << '\n';
        }
    }

    return 0;
}

/*
Logic :
1. cyclic problem tai duibar niye new string kora hoyeche
2. reverse kore g er sathe k er maximum distance ber kora hoyeche
/*
