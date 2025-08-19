#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t ; cin >> t ;
    while ( t-- ){
        unsigned int n ; cin >> n ; 
        // flip in a particular position : num = num ^ (1 << position) 
        // flip the full number : ~num 
    
    
        // for ( int i = 0 ; i < 32 ; i++ ){
        //     n = n ^(1LL << i);
        // }
        cout << ~n << '\n';
    }
    return 0 ;
}
