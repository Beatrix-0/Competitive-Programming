#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>> n ;
    int a[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin>> a[i];
    }
    for ( int i = 1 ; i < n ; i++ )
    {
        int k = a[i];
        int j = i-1;
        while ( a[j] > k && j >= 0 )
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k ;
    }
    for ( int i = 0 ; i < n ; i++ )
    {
        cout << a[i] << " ";
    }
    cout << '\n';


    return 0 ;
}
