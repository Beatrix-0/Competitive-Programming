#include<bits/stdc++.h> // O(n)
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int sum = 0;
    int sq_sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        sum += v[i];
        sq_sum += v[i] * v[i];
    }
    
    int ans = (sum * sum - sq_sum) / 2;
    
    return 0;
}
