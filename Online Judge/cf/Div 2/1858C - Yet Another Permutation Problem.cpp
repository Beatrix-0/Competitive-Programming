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
        vector<int> permutation;
        vector<bool> used(n + 1, false);

        int x = 1;
        for (int i = 2; i <= n; i++)
        {
            if (!used[i])
            {
                permutation.push_back(i);
                used[i] = true;
                x = i;
                while (x * 2 <= n)
                {
                    x = 2 * x;
                    used[x] = true;  
                    permutation.push_back(x);
                }
            }
        }
        cout << 1 << " ";
        for (auto it : permutation)
        {
            cout << it << " ";
        }
        cout << '\n';
    }

    return 0;
}
/*
Problem link : https://codeforces.com/problemset/problem/1858/C

Video solve : https://youtu.be/b_8TbFRkh40?feature=shared

Logic :
    1. sob golo permutation false korchi 
    2. 2 theke n porjonto multiple goloke adjacent korchi, 1
    bad dewar karon 1 sobar multiple 
    3. jegola niye kaj korcho ogola true korchi 
    jeno next e ogola niye kaj na korte hoy 
    4. vector e permutation gola insert korchi 
    
    NOTE :  adjacent multiple e GCD maximum hoy ***
*/
