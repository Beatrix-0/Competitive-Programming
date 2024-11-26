#include<bits/stdc++.h> // Logic + Code 
using namespace std ;
int main()
{
    int s , n;
    cin>> s>> n ;

    pair < int , int > a[n];

    for ( int i = 0 ; i< n ; i++ )
    {
        cin>>a[i].first;
        cin>>a[i].second;
    }

    sort ( a , a+ n );

    bool ans = true ;
    for ( int i = 0 ; i< n ; i++ )
    {
        if ( a[i].first >= s )
        {
            ans = false ;
            break ;
        }
        else
        {
            s = s + a[i].second ;
        }
    }

    if ( ans )
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }

    return 0;
}

// Choto theke boro sragon er dike jabo r extra strength golo add korbo 