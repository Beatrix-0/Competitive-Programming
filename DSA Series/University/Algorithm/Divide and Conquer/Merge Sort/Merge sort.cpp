#include<bits/stdc++.h>
using namespace std ;

const int mx = 1e5+123;
vector< int > v ;
int n ;

void merge_( int lo, int mid, int hi )
{
    int l = lo ;
    int r = mid+1;

    vector < int > tmp ;
    // basic 2 pointer approach
    while ( l <= mid && r <= hi )
    {
        if ( v[l] <= v[r])
        {
            tmp.push_back(v[l]);
            l++;
        }
        else
        {
            tmp.push_back(v[r]);
            r++;
        }
    }
    // Remaning element
    while ( l <= mid )
    {
        tmp.push_back(v[l]);
        l++;
    }
    while ( r <= hi )
    {
        tmp.push_back(v[r]);
        r++;
    }

    // inserting in main array
    for ( int i = lo ; i <= hi ; i++ )
    {
        v[i] = tmp[i-lo];
    }


}

void merge_sort( int lo, int hi )
{
    if ( lo >= hi ) return ;
    int mid = (lo+hi)/2;
    merge_sort( lo, mid );
    merge_sort( mid+1, hi );
    merge_( lo, mid, hi );
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
    merge_sort( 0, n-1 );
    for ( auto it : v )
    {
        cout << it << " ";
    }
    cout << '\n';


    return 0 ;
}

/*
5 
5 4 3 2 1
Resource : https://youtu.be/ogjf7ORKfd8?si=UhNo3hlYE7K3YnH_ 
*/