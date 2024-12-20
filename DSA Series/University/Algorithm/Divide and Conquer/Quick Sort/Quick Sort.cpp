#include<bits/stdc++.h>
using namespace std ;

const int mx = 1e5+123;
vector < int > v;
int n ;

int Partition( int low, int high )
{
    // Consider 1st element as pivot
    int pivot = v[low];
    int l = low, r = high ;
    while ( l < r )
    {
        while ( v[l] <= pivot && l <= high - 1 )
        {
            l++;
        }
        while ( v[r] > pivot && r >= low + 1 )
        {
            r--;
        }
        if ( l < r )
        {
            swap( v[l], v[r]);
        }
    }
    swap( v[low], v[r]);
    return r ;
}

void quick_sort( int lo, int hi )
{
    if ( lo < hi )
    {
        int P_ind = Partition(lo, hi );
        quick_sort( lo, P_ind-1 );
        quick_sort( P_ind+1, hi );
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n ;
    v.resize(n);
    for ( int i = 0 ; i < n ; i++ )
    {
        cin>> v[i];
    }
    quick_sort( 0, n-1 );
    for( auto it : v )
    {
        cout << it << " ";
    }
    cout << '\n';

    return 0 ;
}
/*
5
5 4 3 2 1
Resource : https://youtu.be/WIrA4YexLRQ?si=2wknYIZpKS6Jtpm2
*/