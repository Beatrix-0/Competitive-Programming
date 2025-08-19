#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ,  k;
    cin>> n >> k;

    // By right shift ( prefarable )
    if ( (n >> k ) & 1 ){
        cout << "The kth bit is on" << '\n';
    }
    else{
        cout << "The kth bit is off" << '\n';
    }

    // By left shift
    // When n is greater then 32 bit and less then 64 bit 
    // condition : if ( n & ( 1LL << k )
    if ( n & ( 1 << k )){
        cout << "The kth bit is on" << '\n';
    }
    else{
        cout << "The kth bit is off" << '\n';
    }


    return 0;
}