// Topic 01 : Integer bisection 

//Code 01 :
#include <bits/stdc++.h> // find the index of target by using binary search 
using namespace std;

int bs( vector<int> &v , int n , int target )
{
    int l = 0 ;
    int r = n - 1 ;
    while ( l <= r )
    {
        int mid = ( l + r )/2;
        if ( v[mid] == target )
        {
            return mid ;
            break ;
        }
        else if ( v[mid] > target )
        {
            r = mid - 1 ;
        }
        else
        {
            l = mid + 1 ;
        }
    }
    return -1 ;
}

int main()
{
    vector <int> v = { 0 , 1 , 3 , 6 , 10 , 15 , 21 , 28 , 36 }; // n*(n+1)/2 function e calculate kora
    int target ; cin>> target ;
    int ans = bs ( v , v.size() , target );
    cout << ans << '\n';

}

//Code 02 : 
#include <bits/stdc++.h> // find the index of target by using bisection method 
using namespace std;

int bisection ( int x ) // function : n*(n + 1)/2
{
    return x * (x+1) / 2 ;
}

int bs( int n , int target  )
{
    int l = 0 ;
    int r = n - 1 ;
    while ( l <= r )
    {
        int mid = ( l + r )/2;
        if ( bisection( mid ) == target )
        {
            return mid ;
            break ;
        }
        else if ( bisection( mid ) > target )
        {
            r = mid - 1 ;
        }
        else
        {
            l = mid + 1 ;
        }
    }
    return -1 ;
}

int main()
{
    int n ; cin>> n ; // No need to declare a array , just need to declare the size and target 
    int target ; cin>> target ;
    int ans = bs ( n , target  );
    cout << ans << '\n';

}

Practice Problem :

1. https://www.spoj.com/problems/MATHLOVE/
2. https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monks-encounter-with-polynomial/
3. https://www.spoj.com/problems/RPLC/
4. https://www.spoj.com/problems/SABBIRGAME/

-----------------------------------------------------------------------------------------------------------------------------------------------

// Topic 02 : Fraction bisection 

//Code 01 :
#include<bits/stdc++.h>
using namespace std;
int main()
{

    int x ;
    cin>> x ;

    double l = 0 , r = x ;
    double eps = 1e-6 ; // dosomik er por koto diff er por ans cacchi seta set kora hoyeche 
    while ( r - l > eps )
    {
        double mid = ( l + r )/2 ;
        if ( mid * mid <= x )
        {
            l = mid ;
        }
        else
        {
            r = mid ;
        }
    }

    cout << fixed << setprecision(5) << l << '\n';

    return 0 ;
}

Practice Problem :
1. https://www.geeksforgeeks.org/problems/square-root/1
2. https://lightoj.com/problem/triangle-partitioning
   Code : https://shorturl.at/tHJOV
3. https://lightoj.com/problem/crossed-ladders
   Code : https://shorturl.at/sKOPW
4. https://lightoj.com/problem/expanding-rods
   Code : https://shorturl.at/hvCI5