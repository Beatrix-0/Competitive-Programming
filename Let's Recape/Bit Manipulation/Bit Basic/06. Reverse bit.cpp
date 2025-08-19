#include<bits/stdc++.h>
using namespace std ;

int reverse_bits(int n) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        int bit = (n >> i) & 1;      
        res |= (bit << (31 - i)); 
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc ; cin>> tc ;
    for ( int i = 1 ; i <= tc ; i++ ){
        unsigned n ; cin >> n ;
        n = reverse_bits(n);
        cout << n << '\n';
    }
    
    return 0 ;
}
