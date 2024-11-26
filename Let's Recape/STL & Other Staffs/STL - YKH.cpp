// Topic 01 : Vector 
//Code :
#include<bits/stdc++.h>
using namespace std ;
int main ()
{
    vector <int> a ;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    cout << a[0] << " " << a[1] << '\n';
    int sz = a.size() ;
    for ( int i = 0 ; i< sz ; i++ )
    {
        cout << a[i] << " ";
    }
    cout << '\n';


    vector <int> v ;
    int n ; cin >> n ;
    for ( int i = 0 ; i< n ;i++ )
    {
        int x ;
        cin>> x ;
        v.push_back( x );
    }
    for ( int i = 0 ; i< v.size() ;i++ )
    {
        cout << v[i] << " ";
    }
    cout << '\n';
    v.pop_back();
    for ( int i = 0 ; i< v.size() ;i++ )
    {
        cout << v[i] << " ";
    }
    cout << '\n';


    vector<int>cur ({1 , 2 , 3});
    auto beg = cur.begin();
    cout << (*beg) << '\n';
    beg++;
    cout << ( *beg ) << '\n';
    beg++;
    cout << (*beg) << '\n';
    for ( auto it = cur.begin(); it != cur.end() ; it++)
    {
        cout << (*it) << " ";
    }
    cout << '\n';
    auto itt = cur.begin() + 1 ;
    cout << (*itt) << '\n';
    auto lastit == --cur.end();


    a = vector<int>({1 , 2 , 3 });
    reverse ( a.begin() , a.begin() + 2 );
    for ( auto it : a )
    {
        cout << it << " ";
    }
    cout << '\n';

    a = vector<int>({1 , 2 , 3 });
    a.erase( a.begin());
    for ( auto it : a )
    {
        cout << it << " ";
    }
    cout << '\n';

    return 0 ;
}

// Topic 02 : Pair 
//Code :
#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair <int ,int > pr;
    pr = make_pair( 0 , 3 );
    cout << pr.first << " " << pr.second << '\n';
    pair <int ,int > p1 , p2 ;
    p1 = make_pair( 0 , 3 );
    p1 = make_pair( 1 , 5 );
    swap( p1 , p2 );
    cout << p1.first << " " << p1.second << '\n';


    pair <int ,int > points[10]; // array of pairs 
    pair <string , int > you = ( "Siam" , 201252);
    pair <pair < int ,int > , int > x = (make_pair( 0 , 1 ) , 2 );


    pair <int , int > y ;
    cin>> y.firsy >> y.second ;
    cout << y.first + y.second << '\n';


    return 0;
}

//Topic 03 : Tuple 
// Code :

#include<bits/stdc++.h>
using namespace std;
int main()
{
tuple<int , int , int , int > x ;
tuple<int , int , string , char > y ;

x = make_tuple ( 4 , 2 , 1 , 3 );
cout << (get<0>(x)) << " "<< (get<1>(x)) << '\n';
return 0 ;

}

//Topic 04 : Map
//Code:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map < int, string > mp;
    mp[2] = "two";
    mp[100] = "hundred";
    mp[2] = "twotwo"; // two cancel hoye twotwo assign hoye geche 
    mp[3] = "three";
    auto it = mp.begin();
    cout << (*it).first << " " << (*it).second << '\n';
    cout << it -> first << " " << it -> second << '\n';
    for ( auto it = mp.begin() ; it != mp.end() ; it++ )
    {
        cout << it -> first << " " << it -> second << '\n';
    }
    for ( auto it : mp )
    {
        cout << it.first << " " << it.second << '\n';
    }
    cout << mp[mp] << '\n';
    cout << mp.size() << '\n';
    mp[4];
    cout << mp.size() << '\n';


    map<int , int > m;
    m[1]++;
    m[3] = 2 ;
    cout << m[1] << '\n';
    if ( m.find(1) != m.end())
    {
        cout << "1 exists" << '\n';
    }

    return 0 ;

}

//Topic 05 : Queue
//Code :
#include <bits/stdc++.h>
using namespace std;

int main()
{

    queue<int> q;
    q.push(22);
    q.push(33);
    q.push(44);

    cout << q.front() << '\n';

    q.pop();

    cout << q.front() << '\n';
    cout << q.size() << '\n';
    cout << q.empty() << '\n';

    return 0;
}


//Topic 06 : Stack
//Code :
#include <bits/stdc++.h>
using namespace std;

int main() {


    stack<int> st;
    st.push(22);
    st.push(33);
    st.push(44);

    cout << st.top() << '\n';

    st.pop();

    cout << st.top() << '\n';

    return 0;
}


//Topic 07 : Priority_Queue
//Code :
#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(int a, int b) const
    {
        return a * a < b * b;
    }
};

int main()
{

    priority_queue<int> pq;
    pq.push(22);
    pq.push(33);
    pq.push(44);

    cout << pq.top() << '\n';
    pq.pop();
    cout << pq.top() << '\n';
    cout << pq.size() << '\n';
    cout << pq.empty() << '\n';

    priority_queue<int, vector<int>, greater<int>> min_q;
    min_q.push(44);
    min_q.push(22);
    min_q.push(33);

    cout << min_q.top() << '\n';

    priority_queue<int, vector<int>, cmp> custome; // customize kore kora  
    custome.push(44);
    custome.push(22);
    custome.push(33);

    cout << custome.top() << '\n';

    return 0;
}


//Topic 08 : Dqueue
//Code :
#include <bits/stdc++.h>
using namespace std;

void print(const deque<int>& dq)
{
    for (auto it : dq)
    {
        cout << it << ' ';
    }
    cout << '\n';
}

int main()
{


    deque<int> dq;
    dq.push_back(22);
    dq.push_back(44);
    dq.push_back(33);

    cout << dq[0] << '\n' << '\n';

    print(dq);

    dq.pop_back();
    print(dq);

    dq.push_front(77);
    print(dq);

    dq.pop_front();
    print(dq);

    return 0;
}


//Topic 09 : Multiset
//Code :
#include <bits/stdc++.h>
using namespace std;

void print(const multiset<int>& se)
{
    for (auto it : se)
    {
        cout << it << ' ';
    }
    cout << '\n' << '\n';
}

int main()
{

    multiset<int> se1;
    se1.insert(22);
    se1.insert(33);
    se1.insert(22);
    se1.insert(22);
    se1.insert(11);

    print(se1);

    auto se2 = se1;
    se1.erase(22);
    print(se1);

    auto it = se2.find(22);
    if (it != se2.end())
    {
        se2.erase(it);
    }
    print(se2);

    return 0;
}


//Topic 10 : Multimap
//Code :
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> mp;

    mp[3] = 2;
    mp[5] = 2;
    mp[2] = 1;
    mp[23] = 1;
    mp[1] = 22;

    for ( auto it : mp)
    {
        cout << it.first << ' ' << it.second << '\n';
    }

    unordered_map<int, int> cnt;

    // Input 
    // 5
    // 3 2 4 5 5
    // find the maximum frequency of any element 

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for ( auto it : cnt)
    {
        ans = max(ans, it.second);
    }

    cout << ans << '\n';

    return 0;
}

//Topic 11 : Pointer 
//Code :
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int x = 4;
    cout << (&x) << '\n';

    int *p;
    p = &x;
    cout << (*p) << '\n';

    *p = 20;
    cout << (*p) << '\n';
    cout << x << '\n';

    return 0;
}

//Topic 12 : 
//Code :
#include<bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    string name;
} q, w;

int main()
{

    Point p;
    p.x = 10;
    p.y = 20;
    p.name = "Siam";

    cout << p.x + p.y << '\n';
    cout << p.name << '\n';

    return 0;
}


//Topic 13 : String 
//Code :
#include<bits/stdc++.h>
using namespace std;

int main()
{

    string s = "abcd";
    cout << s << '\n';

    s.push_back('e');
    cout << s << '\n';

    // s += 'e'; => O(1)
    // s = s + 'e'; -> O(len(s))


    s = "e" + s;
    cout << s << '\n';

    string a = "xy", b = "yz";
    cout << a + b << '\n';

    reverse(s.begin(), s.end());
    cout << s << '\n';

    return 0;
}

/* Important: For a string s and a character ch , s += ch is while s = s + ch is O(len(s)) */


//Topic 14 : Stringstream
//Code :
#include<bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    getline(cin, s);

    stringstream ss(s);
    string word;

    while (ss >> word)
    {
        cout << word << '\n';
    }

    return 0;
}





