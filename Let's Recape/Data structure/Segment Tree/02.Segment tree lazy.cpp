#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
int a[N];

struct SegmentTree
{
#define lc (n << 1) // (n << 1) = 2*n
#define rc ((n << 1) + 1) // ((n << 1) + 1) = 2*n+1

    long long t[4 * N], lazy[4 * N];

    SegmentTree()
    {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }

    inline void push(int n, int b, int e) // Change this
    {
        if (lazy[n] != 0)
        {
            t[n] += lazy[n] * (e - b + 1);
            if (b != e)  
            {
                lazy[lc] += lazy[n];
                lazy[rc] += lazy[n];
            }
            lazy[n] = 0; 
        }
    }

    inline long long combine(long long a, long long b) // Change this
    {
        return a + b;
    }

    inline void pull(int n) // change this
    {
        t[n] = combine(t[lc], t[rc]);
    }

    void build(int n, int b, int e)
    {
        lazy[n] = 0;  // change this
        if (b == e)
        {
            t[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n);          
    }

    void upd(int n, int b, int e, int i, int j, long long v)
    {
        push(n, b, e);  // Apply any pending updates before continuing
        if (j < b || i > e) return;
        if (i <= b && e <= j)
        {
            lazy[n] = v;  // Set lazy for this node ( Change section )
            push(n, b, e); 
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n);
    }

    long long query(int n, int b, int e, int i, int j)
    {
        push(n, b, e);
        if (i > e || b > j) return 0; // return null
        if (i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }

    t.build(1, 1, n);  // Building the segment tree

    t.upd(1, 1, n, 2, 3, 10);  // Adding 10 to the segment [2, 3]

    cout << t.query(1, 1, n, 1, 5) << '\n';  // Range sum query on the segment [1, 5]

    return 0;
}

/* What can we do :
1. Single Update, Range Sum Query
    - Update a single element in the array and then query the sum of elements over a range.
2. Single Update, Range Max/Min/GCD/LCM/OR/AND/XOR Query
   - Update a single element and then query the maximum, minimum, GCD, LCM, OR, AND, or XOR of a range.
3.  Range Add Update, Single Query
   - Add a value to all elements in a specified range and then query a single element.
4. Range Add Update, Range Sum Query
   - Description: Add a value to all elements in a specified range and then query the sum of
5. Range Add Update, Range Max/Min Query
   - Add a value to all elements in a specified range and then query the maximum or minimum of elements in another range.
6. Range Assignment Update, Range Sum/Max/Min Query
 - Assign a value to all elements in a specified range and then query the sum, maximum, or minimum of elements in another range.
 */
