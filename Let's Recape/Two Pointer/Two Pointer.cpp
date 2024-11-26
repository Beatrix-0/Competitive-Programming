// Topic : Two pointer  (wrong submission )
// Q1 : Find the pair whose sum is equal to x 
#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(int a[], int n, int x)
{
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        int sum = a[l] + a[r];
        if (sum == x)
        {
            return {a[l], a[r]};
        }
        if (sum > x)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return {-1, -1};
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n); // Sort the array in ascending order.

    int target;
    cin >> target;

    pair<int, int> res = solve(a, n, target);

    if (res.first == -1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << res.first << ' ' << res.second << '\n';
    }

    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------------------

//Q2 : Find the pair in Array Whose sum is closest to X
#include <bits/stdc++.h> 
using namespace std;

void solve(int a[], int n, int x)
{
    int l = 0; // 1st index ( Left )
    int r = n - 1; // last index ( Right )

    int ind_l, ind_r;
    int diff = INT_MAX;

    while (l < r)
    {
        int sum = a[l] + a[r];
        if (abs(x - sum) < diff)
        {
            ind_l = l;
            ind_r = r;

            diff = abs(x - sum);
        }

        if (sum > x)
        {
            r--;
        }
        else
        {
            l++;
        }
    }


    cout << a[ind_l] << " + " << a[ind_r] << " = " << a[ind_l] + a[ind_r] << '\n';

}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int target ;
    cin >> target ;

    solve(a, n, target );

    return 0;
}

Problem statement :
1. https://www.geeksforgeeks.org/given-sorted-array-number-x-find-pair-array-whose-sum-closest-x/

------------------------------------------------------------------------------------------------------------------------------------------------

//Q3 : Find the closest pair from two sorted arrays
#include <bits/stdc++.h> 
using namespace std;

void solve(int a[], int b[], int n, int m, int x)
{
    int l = 0;
    int r = m - 1;
    int ind_l, ind_r;
    int diff = INT_MAX;

    while (l < n && r >= 0)
    {
        int sum = a[l] + b[r];
        if (abs(sum - x) < diff)
        {
            ind_l = l;
            ind_r = r;
            diff = abs(sum - x);
        }
        if (sum > x)
        {
            r--;
        }
        else
        {
            l++;
        }
    }

    cout << a[ind_l] << " " << b[ind_r] << " = " << a[ind_l] + b[ind_r] << '\n';
}

int main()
{
    int n, m, x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin>>m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    cin>>x;

    solve(a, b, n, m, x);

    return 0;
}

Problem statement :
1. https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/

------------------------------------------------------------------------------------------------------------------------------------------------

// Q4 : Find all triplets with zero sum
#include <bits/stdc++.h> 
using namespace std;

void solve(int a[], int n)
{
    for (int i = 0; i < n; i++) 
    {
        set<int> s;
        for (int j = i + 1; j < n; j++)
        {
            int x = -(a[i] + a[j]);
            if (s.find(x) != s.end())
            {
                cout << "( " << x << " , " << a[i] << " , " << a[j] << " )" << '\n';
            }
            else
            {
                s.insert(a[j]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(a, n);

    return 0;
}

Problem Statement :
1. https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/

------------------------------------------------------------------------------------------------------------------------------------------------

//Q5 : Find a triplet that sum to a given value 
#include<bits/stdc++.h> 
using namespace std;

void solve ( int a[], int n, int x )
{
    for ( int i = 0 ; i< n ; i++)
    {
        set<int>s;
        for ( int j = i+1; j< n ; j++)
        {
            int sum = a[i] + a[j];
            int d = abs ( x - sum );
            if ( s.find(d) != s.end())
            {
                cout << "( " << d << " , "  << a[i] << " , "  << a[j] << " )"  << '\n';
            }
            else
            {
                s.insert(a[j]);
            }
        }
    }

}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i< n ; i++)
    {
        cin>>a[i];
    }
    int x ;
    cin>>x;

    solve ( a, n, x );

    return 0 ;
}

Problem statement :
1. https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/

------------------------------------------------------------------------------------------------------------------------------------------------

//Q6 : Find four elements that sum to a given value 
#include<bits/stdc++.h> 
using namespace std;

void solve ( int a[], int n, int x )
{
    bool ans = true;
    for ( int i = 0 ; i < n ; i++)
    {
        for ( int j = i+1 ; j < n ; j++)
        {
            int l = j+1;
            int r = n-1;
            while ( l < r )
            {
                int sum = a[i] + a[j] + a[l] + a[r];
                if ( sum == x )
                {
                    cout << a[i] << " " <<  a[j] << " " << a[l] <<" "<< a[r] <<'\n';
                    ans = false;
                }
                if ( sum > x )
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
    }

    if ( ans )
    {
        cout << "Value is not found " << '\n';
    }
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for ( int i = 0 ; i< n ; i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    solve( a,n,x );

}

Problem Statement :
1. https://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/

------------------------------------------------------------------------------------------------------------------------------------------------

//Q7 : Find a triplet such that sum of two equals to third element
#include<bits/stdc++.h>
using  namespace  std;

void solve(int ar[],int n)
{
    for(int i = n-1; i >= 0; i--)
    {
        int x =ar[i];
        int l=0;
        int r=i-1;
        while(l<r)
        {
            int sum=ar[l]+ar[r];
            if(sum==x)
            {
                cout<<"("<<x<<","<<ar[l]<<","<<ar[r]<<")"<<endl;
                return;
            }
            if(sum>x)r--;
            else l++;
        }
    }
    cout<<"No Such Triplates exists"<<endl;
}
int main()
{
    int n; cin>>n;
    
    int ar[n];
    for(int i=0; i<n; i++)cin>>ar[i];
    
    sort(ar,ar+n);
    solve(ar,n);
}

Problem statement :
1. https://www.geeksforgeeks.org/find-triplet-sum-two-equals-third-element/


------------------------------------------------------------------------------------------------------------------------------------------------
Some Random practice problem 

ITMU Practice question link : https://codeforces.com/edu/course/2

1. https://codeforces.com/problemset/problem/1462/A
2. https://codeforces.com/problemset/problem/381/A
3. https://codeforces.com/contest/1006/problem/C
4. https://codeforces.com/contest/1251/problem/A
5. https://codeforces.com/contest/1669/problem/F
6. https://cses.fi/problemset/task/1084
7. https://cses.fi/problemset/task/1090
8. https://codeforces.com/contest/1921/problem/D
9. https://codeforces.com/contest/1843/problem/A