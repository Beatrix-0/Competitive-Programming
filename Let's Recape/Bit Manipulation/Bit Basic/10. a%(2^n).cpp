#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a , n ;
    cin >> a >> n;

    cout << ( a & (( 1 << n ) - 1) );

    return 0;
}