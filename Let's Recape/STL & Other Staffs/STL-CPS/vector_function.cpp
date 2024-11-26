// Video Link : https://youtu.be/W1McvE4a910?si=xOHPi0e7xxcAOpG0 https://youtu.be/1qrlDngStmU?si=CC7XlLDkZvNNZRu5

/// In the name of ALLAH
 
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    vector<int> v;
 
    v.push_back( 1 );
    v.push_back( 2 );
    v.push_back( 3 );
 
    cout << v[0] << " " << v[1] << " " << v[2] << endl; /// 1 2 3
 
    v[1] = 3;
    cout << v[0] << " " << v[1] << " " << v[2] << endl; /// 1 3 3
 
    cout << v.size() << endl; /// 3
    for ( int i = 0; i < v.size(); i++ ) cout << v[i] << " "; /// 1 3 3
    cout << endl;
 
    vector <int> v1 = { 2, 3, 4 };
 
    cout << v1.size() << endl; /// 3
    for ( int i = 0; i < v1.size(); i++ ) cout << v1[i] << " "; /// 2 3 4
    cout << endl;
 
    v.clear();
    cout << v.size() << endl; /// 0
    cout << v.empty() << endl; /// 1
    cout << v1.empty() << endl; /// 0
 
    v1.resize(5);
    cout << v1.size() << endl; /// 5
    for ( int i = 0; i < v1.size(); i++ ) cout << v1[i] << " "; /// 2 3 4 0 0
    cout << endl;
 
    vector<int> a(5);
 
    cout << a.size() << endl; /// 5
    for ( int i = 0; i < a.size(); i++ ) cout << a[i] << " "; /// 0 0 0 0 0
    cout << endl;
 
    a = v1;
 
    for ( auto u : a ) cout << u << " "; /// 2 3 4 0 0
    cout << endl;
 
    vector<int>::iterator it;
    for ( it = a.begin(); it != a.end(); it++ ) cout << *it << " "; /// 2 3 4 0 0
    cout << endl;
 
    a = { 3, 4, 5, 1, 2 };
 
    sort ( a.begin(), a.end() ); ///O(n*log2(n))
 
    for ( auto u : a ) cout << u << " "; /// 1 2 3 4 5
    cout << endl;
 
    sort ( a.rbegin(), a.rend() );
 
    for ( auto u : a ) cout << u << " "; /// 5 4 3 2 1
    cout << endl;
 
 
    a = { 3, 4, 5, 1, 2 };
    sort ( a.begin(), a.end(), greater<int>() );
 
    for ( auto u : a ) cout << u << " "; /// 5 4 3 2 1
    cout << endl;
 
    a = { 3, 4, 5, 1, 2 };
 
    reverse( a.begin(), a.end() );
 
    for ( auto u : a ) cout << u << " "; /// 2 1 5 4 3
    cout << endl;
 
    cout << a.back() << endl; /// 3
    a.pop_back(); /// O(1) complexity.
    cout << a.back() << endl; /// 4
 
 
    a = { 3, 4, 5, 1, 2 };
    cout << *a.begin() << endl; /// 3
 
    a.erase( a.begin() ); /// O(n) complexity.
    for ( auto u : a ) cout << u << " "; /// 4 5 1 2
    cout << endl;
 
    a.erase( a.begin()+2 );
    for ( auto u : a ) cout << u << " "; /// 4 5 2
    cout << endl;
 
    a = { 1, 1, 2, 2, 2, 3, 3 };
    unique( a.begin(), a.end() );
 
    for ( auto u : a ) cout << u << " "; /// 1 2 3 2 2 3 3
    cout << endl;
 
 
    a = { 1, 1, 2, 2, 2, 3, 3 };
    int n = unique( a.begin(), a.end() ) - a.begin();
 
    cout << n << endl; /// 3
    for ( int i = 0; i < n; i++ ) cout << a[i] << " "; /// 1 2 3
    cout << endl;

    // Removing the duplicates 
     a.erase(unique(a.begin(), a.end()), a.end());
 
    a = { 2, 3, 1, 5 };
    cout << max_element( a.begin(), a.end() ) - a.begin() << endl; /// 3
    cout << *max_element( a.begin(), a.end() ) << endl; /// 5
 
    return 0;
}



/* Some question link .... the ans will be the link as well 

1. https://codeforces.com/problemset/problem/381/A
2. https://leetcode.com/problems/peak-index-in-a-mountain-array/
3. https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
4. https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/distinct-count/submissions/
5. https://codeforces.com/problemset/problem/22/A

*/