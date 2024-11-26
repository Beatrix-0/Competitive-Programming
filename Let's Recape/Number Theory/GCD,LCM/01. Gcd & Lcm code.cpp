#include<bits/stdc++.h> // Calculate GCD --> Euclid Algorithm
using namespace std;

int gcd( int a, int b )
{
    if ( b == 0 )
    {
        return a ;
    }
    else
    {
        return gcd ( b, a%b );
    }
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int a,b;
    cin>>a>>b;

    // Printing GCD
    int ans_gcd = gcd(a,b);
    cout << "GCD : "<<  ans_gcd << '\n';

    // Printing LCM
    int ans_lcm =  ( a , b ) ;
    cout << "LCM : "<<  ans_lcm << '\n';


    return 0;
}