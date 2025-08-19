#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>> n ;
    if ( n & 1 ) {
        cout << "The last bit is on" << '\n';
        cout << "The number is odd" << '\n';
    }
    else {
        cout << "The last bit is off " << '\n';
        cout << "The number is even" << '\n';
    }
    return 0;
}