//Topic 01 : Binary Search code 
//Code : Basic code 
#include<bits/stdc++.h> // Binary Search 
using namespace std;

int binarySearch (int a[] , int n , int target )
{
    int l , r , mid;
    l = 0 ;
    r = n-1;
    while( l <= r )
    {
        mid = (l+r)/2;

        if ( target == a[mid])
        {
            return mid;
        }
        else if ( target > a[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return -1; // jokhon target array moddhe thakbe na

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ;
        cin>>n >> x;
        int a[n];
        for ( int i = 0 ; i<n ; i++)
        {
            cin>>a[i];
        }
        sort( a , a+n);

        int res = binarySearch ( a , n , x ); // m = target

        cout << res << '\n';
    }

    return 0;
}

// Code : Binary search by using recusrion 
#include<bits/stdc++.h> 
using namespace std;

int recursive_Bs(int a[], int l, int r, int target)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;

        if (target == a[mid])
        {
            return mid;
        }
        else if (target > a[mid])
        {
            return recursive_Bs(a, mid + 1, r, target);
        }
        else
        {
            return recursive_Bs(a, l, mid - 1, target);
        }
    }

    return -1; 
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);

        int res = recursive_Bs(a, 0, n - 1, x); // x = target

        cout << res << '\n';
    }

    return 0;
}


// Code : Find the 1st oc ans Last oc ( upper_bound and lower_bound )
#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int x;
    cin >> x;

    sort(a, a + n);

    vector<int> v;

    // Searching for 1st occurrence
    int l = 0, r = n - 1;
    int first_oc = INT_MAX;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (a[mid] == x)
        {
            first_oc = min(mid, first_oc);
        }

        if (a[mid] >= x) // soman holeo ekto right e check kore asbe 
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (first_oc == INT_MAX)
    {
        first_oc = 0;
    }

    // Searching for last occurrence
    int l2 = 0, r2 = n - 1;
    int last_oc = INT_MIN;

    while (l2 <= r2)
    {
        int mid = (l2 + r2) / 2;

        if (a[mid] == x)
        {
            last_oc = max(mid, last_oc);
        }

        if (a[mid] <= x) // soman holeo ekto left e check kore asbe 
        {
            l2 = mid + 1;
        }
        else
        {
            r2 = mid - 1;
        }
    }

    if (last_oc == INT_MIN)
    {
        last_oc = 0;
    }

   cout << first_oc << " " << last_oc << '\n';

    return 0;
}

Practice Problem :
1. https://leetcode.com/problems/binary-search/
2. https://leetcode.com/problems/intersection-of-two-arrays/
3. https://www.spoj.com/problems/BSEARCH1/en/
4. https://codeforces.com/problemset/problem/1850/E
----------------------------------------------------------------------------------------------------------------------------------------------

// Question //

// Q1 : Binary search on reverse sorted array 
#include<bits/stdc++.h> 
using namespace std;

int binarySearch(int a[], int n, int target)
{
    int l, r, mid;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        mid = (l + r) / 2;

        if (target == a[mid])
        {
            return mid;
        }
        else if (target > a[mid])  
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return -1; // jokhon target array moddhe thakbe na
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int res = binarySearch(a, n, x); // x = target

        cout << res << '\n';
    }

    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------

//Q2 : First and last occurrences of an array 
#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int x;
    cin >> x;

    sort(a, a + n);

    vector<int> v;

    // Searching for 1st occurrence
    int l = 0, r = n - 1;
    int first_oc = INT_MAX;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (a[mid] == x)
        {
            first_oc = min(mid, first_oc);
        }

        if (a[mid] >= x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (first_oc == INT_MAX)
    {
        first_oc = 0;
    }

    // Searching for last occurrence
    int l2 = 0, r2 = n - 1;
    int last_oc = INT_MIN;

    while (l2 <= r2)
    {
        int mid = (l2 + r2) / 2;

        if (a[mid] == x)
        {
            last_oc = max(mid, last_oc);
        }

        if (a[mid] <= x)
        {
            l2 = mid + 1;
        }
        else
        {
            r2 = mid - 1;
        }
    }

    if (last_oc == INT_MIN)
    {
        last_oc = 0;
    }

   cout << first_oc << " " << last_oc << '\n';

    return 0;
}

Practice problem :
1. https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/

----------------------------------------------------------------------------------------------------------------------------------------------

// Q3 :  Count of an elemnet in a sorted array 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int x;
    cin >> x;

    sort(a, a + n);

    vector<int> v;

    // Searching for 1st occurrence
    int l = 1, r = n ;
    int first_oc = INT_MAX;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (a[mid] == x)
        {
            first_oc = min(mid, first_oc);
        }

        if (a[mid] >= x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (first_oc == INT_MAX)
    {
        first_oc = -1 ;
    }

    // Searching for last occurrence
    int l2 = 0, r2 = n;
    int last_oc = INT_MIN;

    while (l2 <= r2)
    {
        int mid = (l2 + r2) / 2;

        if (a[mid] == x)
        {
            last_oc = max(mid, last_oc);
        }

        if (a[mid] <= x)
        {
            l2 = mid + 1;
        }
        else
        {
            r2 = mid - 1;
        }
    }

    if (last_oc == INT_MIN)
    {
        last_oc = -1 ;
    }

    if ( first_oc == -1 && last_oc == -1 )
    {
        cout << "No occurrence is found " << '\n';
    }
    else
    {
        int oc_cnt = ( last_oc - ( first_oc - 1 ));
        cout << oc_cnt << '\n';
    }

    return 0;
}

Practice problem :
1. https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/

----------------------------------------------------------------------------------------------------------------------------------------------

//Q4 : Number of time a sorted array is rotated 
#include <bits/stdc++.h>
using namespace std;

int min_num(vector<int>& v, int n )
{
    int l = 0;
    int r = n - 1;

    if (n == 1)
    {
        return 0 ;
    }

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (v[mid] < v[prev] && v[mid] < v[next])
        {
            return mid;
        }

        else if (v[r] < v[mid])
        {
            l = mid + 1;
        }

        else
        {
            r = mid - 1;
        }

    }

    return -1;
}

int main()
{
    int n ;
    cin>> n ;
    vector<int> v(n) ;
    for ( int i = 0 ; i< n ; i++ )
    {
        cin>> v[i];
    }
    int ans = min_num(v, n );

    cout << ans << endl;

    return 0;
}

Practice problem :
1. https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

----------------------------------------------------------------------------------------------------------------------------------------------

// Q5 : Find an element in a rotated sorted array 
#include <bits/stdc++.h>
using namespace std;

int bs_right ( vector<int> &v , int mn , int target )
{
    int l = 0 ;
    int r = mn - 1 ;
    while ( l <= r )
    {
        int mid = ( l + r )/2;

        if ( v[mid] == target)
        {
            return mid ;
        }
        else if ( v[mid] < target )
        {
            l = mid + 1 ;
        }
        else
        {
            r = mid - 1 ;
        }


    }
    return -1 ;
}

int bs_left ( vector<int> &v , int mn , int target )
{
    int l = mn ;
    int r = v.size() - 1  ;
    while ( l <= r )
    {
        int mid = ( l + r )/2;

        if ( v[mid] == target)
        {
            return mid ;
        }
        else if ( v[mid] < target )
        {
            l = mid + 1 ;
        }
        else
        {
            r = mid - 1 ;
        }


    }
    return -1 ;
}


int min_num(vector<int>& v, int n )
{
    int l = 0;
    int r = n - 1;

    if (n == 1)
    {
        return 0 ;
    }

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (v[mid] < v[prev] && v[mid] < v[next])
        {
            return mid;
        }

        else if (v[r] < v[mid])
        {
            l = mid + 1;
        }

        else
        {
            r = mid - 1;
        }

    }

    return -1;
}

int main()
{
    int n ;
    cin>> n ;
    vector<int> v(n) ;
    for ( int i = 0 ; i< n ; i++ )
    {
        cin>> v[i];
    }
    int target ; cin>> target ;

    int mn = min_num(v, n );

    int a = bs_right ( v , mn , target ) ;
    int b = bs_left ( v , mn , target ) ;

    if ( a == -1 && b == -1 )
    {
        cout << -1 << '\n';
    }
    else
    {
        if ( a > -1 )
        {
            cout << a << '\n';
        }
        else
        {
            cout << b << '\n';
        }
    }

    return 0;
}

Practice problem :
1. https://leetcode.com/problems/search-in-rotated-sorted-array/

----------------------------------------------------------------------------------------------------------------------------------------------

// Q6 : Searching an element nearly sorted array 
#include <bits/stdc++.h>
using namespace std;

int search ( vector <int> &v , int n , int target )
{
    int l = 0 ;
    int r = n - 1 ;

    while ( l <= r )
    {
        int mid = ( l + r ) /2 ;

        if ( v[mid] == target )
        {
            return mid ;
        }
        if ( mid - 1 >= l && v[mid-1] == target ) // check korchi jeno element golo array r moddhe thake nahole overflow korbe 
        {
            return mid - 1;
        }
        if ( mid + 1 <= r && v[mid+1] == target )
        {
            return mid + 1 ;
        }
        else if ( v[mid] > target )
        {
            l = mid + 2 ;
        }
        else
        {
            r = mid - 2 ;
        }
    }

    return -1 ;
}


int main()
{
    int n;
    cin>> n;
    vector < int > v(n);
    for ( int i = 0 ;i< n ; i++ )
    {
        cin>>v[i];
    }
    int target ; cin>> target ;

    int ans = search ( v , n , target ) ;
    cout << ans << '\n';


    return 0;
}

Practice problem :
1. https://www.geeksforgeeks.org/search-almost-sorted-array/

----------------------------------------------------------------------------------------------------------------------------------------------

//Q7 : Find floor of an element of an sorted array :
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &v, int n, int target)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (v[mid] == target)
        {
            return v[mid];
        }
        else if (v[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            ans = v[mid];
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int target;
    cin >> target;

    int ans = search(v, n, target);
    cout << ans << '\n';

    return 0;
}

Practice problem :
1. https://www.geeksforgeeks.org/floor-in-a-sorted-array/

----------------------------------------------------------------------------------------------------------------------------------------------

// Q8 :  Find ceil of an element of an sorted array 
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &v, int n, int target)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (v[mid] == target)
        {
            return v[mid];
        }
        else if (v[mid] > target)
        {
            ans = v[mid];
            r = mid - 1;
        }
        else
        {
            
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int target;
    cin >> target;

    int ans = search(v, n, target);
    cout << ans << '\n';

    return 0;
}

Practice problem :
1. https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/

----------------------------------------------------------------------------------------------------------------------------------------------

// Q9 : find the next alphabetic element in a sorted array 
#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter (vector<char> &v, int n, char target)
{
    int l = 0;
    int r = n - 1;
    char ans  = '#';

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (v[mid] == target)
        {
            l = mid + 1 ; // amar target theke boro element lagbe target er soman na

        }
        else if (v[mid] > target)
        {
            ans = v[mid];
            r = mid - 1;
        }
        else
        {

            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    char target;
    cin >> target;

    char ans = nextGreatestLetter (v, n, target);
    if ( ans == '#' )
    {
        cout << "The next charcater is not in array " << '\n';
    }
    else 
    {
    cout << ans << '\n';
    }


    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------

//Q10 : Find position of an element in an infinite sorted array 
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int target )
{
    while ( l <= r )
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            return mid ;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }

        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int findPos(int arr[], int target )
{
    int l = 0, r = 1;
    int val = arr[0];

    while (val < target )
    {
        l = r ;
        r = 2 * r ;
        val = arr[r];
    }

    return binarySearch(arr, l, r, target );
}

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int ans = findPos(arr, 10  );

    if (ans == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;

    return 0;
}

Practice problem :
1. https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/

----------------------------------------------------------------------------------------------------------------------------------------------

// Q11 : Find the index of first '1' in a binary infinite sorted array 
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int target )
{
    int first_oc = INT_MAX ;
    while ( l <= r )
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
        {
            first_oc = min ( first_oc, mid );
        }
        if (arr[mid] >= target) // soman holeo r ow left e search korbo
        {
            r = mid - 1;
        }

        else
        {
            l = mid + 1;
        }
    }
    if ( first_oc == INT_MAX ) return -1 ;
    else return first_oc ;
}

int findPos(int arr[], int target )
{
    int l = 0, r = 1;
    int val = arr[0];

    while (val < target )
    {
        l = r ;
        r = 2 * r ;
        val = arr[r];
    }

    return binarySearch(arr, l, r, target );
}

int main()
{
    int arr[] = { 0, 0,0,0,0,0, 0, 1, 1, 1, 1 };
    int ans = findPos(arr, 1  );

    if (ans == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;

    return 0;
}

Practice problem :
1. https://www.geeksforgeeks.org/find-index-first-1-infinite-sorted-array-0s-1s/

----------------------------------------------------------------------------------------------------------------------------------------------

//Q12 : Find the minimum difference element in a sorted array 
#include <bits/stdc++.h>
using namespace std;

int min_diff (vector<int> &v, int n, int target )
{
    int ans;
    int l = 0, r = n - 1;
    while( l <= r )
    {
        int  mid = ( l + r ) / 2 ;
        if(v[mid] == target )
        {
            return 0 ;
        }
        else if( target  > v[mid])
        {
            l = mid+1;
        }
        else
        {
            r = mid -1;
        }
    }
    if(r >= 0 && l <= n - 1 )
    {
        if( abs( target - v[l] ) > abs( target - v[r]) )
        {
            return abs(target - v[r]);
        }
        else
        {
            return abs(target -v[l]);
        }
    }
    else if( r >= 0)
    {
        return abs(target - v[r] );
    }
    return abs( target - v[l] );

}

int main()
{
    int n;
    cin>> n ;

    vector <int > v(n);
    for ( int i = 0 ; i< n ; i++ )
    {
        cin>> v[i];
    }
    int target ;
    cin>>target ;

    int ans = min_diff ( v, n, target );
    cout << ans << '\n';

    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------

//Q13 : Find the peak element  ( Striver )
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr)
{
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4 , 5, 85, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

Practice problem :
1. https://leetcode.com/problems/find-peak-element/

----------------------------------------------------------------------------------------------------------------------------------------------

// Q14 : Find maximum elementin a bitonic array 
#include <bits/stdc++.h>
using namespace std;

int max_element(vector<int> &arr)
{
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4 , 5, 85, 7, 8, 5, 1};
    int ans = max_element(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

Practice problem :
1. https://www.includehelp.com/icp/maximum-value-in-a-bitonic-array.aspx

----------------------------------------------------------------------------------------------------------------------------------------------

//Q15 : Search an element in a bitonic array 
#include <bits/stdc++.h>
using namespace std;

int bs_1 ( vector<int> &v , int l ,int r ,int target )
{
    while ( l <= r)
    {
        int mid = ( l + r )/2;
        if ( v[mid] == target )
        {
            return mid ;
        }
        else if ( v[mid] > target )
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1 ;
        }
    }
    return -1 ;
}

int bs_2 ( vector<int> &v ,int l ,int r ,int target )
{
    while ( l <= r)
    {
        int mid = ( l + r )/2;
        if ( v[mid] == target )
        {
            return mid ;
        }
        else if ( v[mid] > target )
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1 ;
        }
    }
    return -1 ;
}


int findPeakElement(vector<int> &arr , int n )
{
    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{

    int n ;
    cin>> n ;
    vector <int > v(n);
    for ( int i = 0 ; i< n ; i++ )
    {
        cin>> v[i];
    }
    int target ; cin>> target ;

    int peak = findPeakElement ( v , n );
    int a = bs_1 ( v , 0 , peak-1 , target );
    int b = bs_2 ( v , peak , n-1 , target );

    if ( a == -1 && b == -1 )
    {
        cout << -1 ;
    }
    else
    {
        if ( a > b )
        {
            cout << a << '\n';
        }
        else
        {
            cout << b << '\n';
        }
    }

    return 0;
}


Practice problem :
1. https://www.geeksforgeeks.org/find-element-bitonic-array/

