#include<bits/stdc++.h>
using namespace std ;

int swap_bits( int x , int i , int j ){
    if(  ((x >> i) & 1) != ((x >> j) & 1)){
        int bit_mask = (1 << i) | (1 << j)  ;
        x ^= bit_mask;
    }
    return x ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc ; cin>> tc ;
    for ( int i = 1 ; i <= tc ; i++ ){
        int n ; cin >> n;
        for ( int i = 0 ; i < 32 ; i+=2 ){
            n = swap_bits( n , i , i+1);
        }
        cout << n << '\n';
    }

    return 0 ;
}

// vlog : https://vidyabhandary.medium.com/swap-bits-visual-explanation-27bb0eb83738
