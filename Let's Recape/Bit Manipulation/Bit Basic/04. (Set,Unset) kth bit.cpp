#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n , k ;
   cin>> n >> k ;

    // set Kth bit 
   cout << ( n | ( 1 << k )) << '\n'; 
    // inset Kth bit
   cout << ( n & ( (1 << n )-1 - ( 1 << k ) ))  << '\n'; 

    return 0;
}