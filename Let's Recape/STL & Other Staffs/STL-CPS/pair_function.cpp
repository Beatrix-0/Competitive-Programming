// Video link : https://youtu.be/z74JnD_pZZk?si=IRZ3Ww-4jEK3wbd7

///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///
 
 
 
#include<bits/stdc++.h>
using namespace std;
 
 
bool cmp ( const pair<int,int> &p1, const pair<int, int> &p2  )
{
	if ( p1.first > p2.first ) return 1;
	if ( p1.first == p2.first ) return ( p1.second < p2.second );
	return 0;
}
 
int main()
{
 
	/// Declear a pair o integers
 
	pair<int,int> p;
 
	p = make_pair ( 2, 3 );
	cout << p.first << " " << p.second << endl; /// 2 3
 
	p.first++;
	cout << p.first << " " << p.second << endl; /// 3 3
 
	pair<int, int> p1 = { 2, 3 };
	pair<int, int> p2 = { 1, 6 };
 
	/// Getting minimum of 2 pairs
	p = min ( p1, p2 );
	cout << p.first << " " << p.second << endl; /// 1 6
 
	/// Getting maximum of 2 pairs
	p = max ( p1, p2 );
	cout << p.first << " " << p.second << endl; /// 2 3
 
	/// Sorting pair of integers
 
	vector<pair<int,int>> v;
	v.push_back ( { 1, 5 } );
	v.push_back ( { 2, 5 } );
	v.push_back ( { 7, 1 } );
	v.push_back ( { 3, 6 } );
	v.push_back ( { 3, 6 } );
	v.push_back ( { 7, 1 } );
 
	sort ( v.begin(), v.end() );
	for ( auto u : v ) cout << u.first << " " << u.second << endl;
	cout << endl;
	/**
	1 5
	2 5
	3 6
	3 6
	7 1
	7 1
 
	*/
 
	/// Making unique pair of integers
 
	int Sz = unique ( v.begin(), v.end() ) - v.begin();
	cout << Sz << endl;
	for ( int i = 0; i < Sz; i++ ) cout << v[i].first << " " << v[i].second << endl;
	cout << endl;
 
	/**
	4
	1 5
	2 5
	3 6
	7 1
 
	*/
 
	/// sorting using comparator
	v = { {2, 3}, {4, 5}, {1, 5}, {1, 6}, {6, 7}, {6, 8} };
 
	sort ( v.begin(), v.end(), cmp );
	for ( auto u : v ) cout << u.first << " " << u.second << endl;
	cout << endl;
 
	/**
 
	6 7
	6 8
	4 5
	2 3
	1 5
	1 6
 
	*/
 
 
	v = { {2, 3}, {4, 5}, {1, 5}, {1, 6}, {6, 7}, {6, 8} };
 
	for ( int i = 0; i < v.size(); i++ ) v[i].first *= -1;
	sort ( v.begin(), v.end() );
	for ( auto u : v ) cout << (u.first*-1) << " " << u.second << endl;
	cout << endl;
 
	/**
 
	6 7
	6 8
	4 5
	2 3
	1 5
	1 6
 
	*/
 
 
	return 0;
}

// Some practice question linl ...ans will be in the link 
/*
1. https://codeforces.com/contest/44/problem/A
2. https://practice.geeksforgeeks.org/problems/count-distinct-pairs-with-difference-k1233/1
3. https://codeforces.com/problemset/problem/166/A

*/


// Practice Question : https://codeforces.com/contest/1895/problem/B

//Solve ;
#include<bits/stdc++.h> 
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n;
        m = 2*n;

        vector<int>v(m);
        for ( int i = 0 ; i< 2*n ; i++)
        {
            cin>> v[i];
        }

        sort(v.begin(),v.end());

        vector<pair<int,int>>x(n);

        for ( int i = 0 ; i< n ; i++) // 1st half x er man
        {
            x[i].first = v[i];
        }

        for ( int i = n ; i< m ; i++) // 2nd half y er man
        {
            x[i-n].second = v[i]; // pair er second e 1st index theke value store korar jonno (i-n)
        }

        sort(x.begin(),x.end());

        int ans = 0 ;

        for ( int i = 1 ; i < n ; i++) // 1 ta index beshi nile last index er sathe compare kora jeto na
        {
            ans =ans + (abs(x[i].first - x[i-1].first)) + (abs(x[i].second - x[i-1].second));
        }


        cout<< ans  << '\n';
        for ( auto it : x)
        {
            cout << it.first << " " << it.second <<'\n';
        }
    }

    return 0;
}
