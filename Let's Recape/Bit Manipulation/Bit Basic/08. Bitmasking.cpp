#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int n , k ;
    cin>>n >> k;
    vector < int > v(n);
    for ( int i = 0 ; i< n ; i++){
        cin>> v[i];
    }

    int cnt = 0 ;
    for ( int mask = 0 ; mask < ( 1 << n ) ; mask++ ){ // all possible subset
        int sum = 0 ;
        for (int i = 0 ; i< n ; i++ ){
            if ( (mask >> i )&1){
                sum = sum + v[i];
            }
        }
        if ( sum == k ){
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}