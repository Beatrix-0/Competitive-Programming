#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);

#include <ext/pb_ds/assoc_container.hpp> // 5 line code
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    fast;

    int n;
    cin >> n;
    ordered_set<int> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.insert(x);
    }

    // Output the elements in the ordered set
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << '\n';
    
    // Order_of_key(k): number of elements less than k
    int key = 9 ;
    cout << v.order_of_key(key) << '\n';
    
    // find_by_order(k): returns the iterator[value] of the k-th element in a set (0-index)
    int ind = 3;
    cout << *v.find_by_order(ind) << '\n';
    
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------
// pair of multiset
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    fast;

    int n;
    cin >> n;
    ordered_multiset<int> v;

    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.insert({x, ind++});
    }

    for (auto it : v)
    {
        cout << it.first << " ";
    }
    cout << '\n';

    // Order_of_key(k): number of elements less than k (ignores index part)
    int key = 9;
    cout << v.order_of_key({key, -1}) << '\n';

    // find_by_order(k): returns the k-th element in the multiset (ignores index part)
    int chek_ind = 3;
    if (ind < v.size()) {
        cout << v.find_by_order(chek_ind)->first << '\n';
    } else {
        cout << "Index out of bounds\n";
    }

    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------------------
// Multiset 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> 
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
-------------------------------------------------------------------------------------------------------------------------------------------------



/*
 1. Time complexity O(logn) for both
 2. Can perform all task like set function
 Problem link: https://cses.fi/problemset/task/1144

 input :
 7
 4 8 1 9 2 2 4
  */
/* Practice Problem :
1. https://leetcode.com/problems/count-of-range-sum/description/
2. https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/
3. https://leetcode.com/problems/create-sorted-array-through-instructions/description/
4. https://leetcode.com/problems/reverse-pairs/description/
5. https://codeforces.com/problemset/problem/61/E
6. https://leetcode.com/problems/count-of-range-sum/description/
*/
/*
Resources :
1. https://youtu.be/EckwF4gFG34?si=WVPJ2mpqvo_8cCHR
2. https://youtu.be/IWyIwLFucU4?si=itv_WfZYJQwKsJMs 
*/
