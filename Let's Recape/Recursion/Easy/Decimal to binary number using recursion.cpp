#include <iostream>
using namespace std;

int rec(int n)
{
    if (n > 1)
    {
        return 10 * rec(n / 2) + n % 2;
    }
    else 
    {
        return n;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << rec(n);

    return 0;
}