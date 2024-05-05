#include<bits/stdc++.h>
using namespace std ;

double avg( vector<int>&v , int length  )
{
    if ( length == 1 ) // base case
    {
        return v[0];
    }

    double total = avg( v , length-1 );
    total = total * ( length -1 );
    total = total + v[length-1];

    return total/length;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ; cin>> n ;
    vector < int > v(n);
    for ( int i = 0 ; i < n ; i++ )
    {
        cin>> v[i];
    }

    double x = avg( v , n );
    cout << x << '\n';


    return 0 ;
}
