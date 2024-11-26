/* How to get frequency from map function */ // Siam ahmed 

#include<bits/stdc++.h>
using namespace std;
int main()
{

  vector<long long > v = {124552112,12,12,12,5,1025532554655,36540252355366553};

   map<long long , int >cnt;

   for (auto it : v)
   {
       cnt[it]++;
   }

   for (auto it : cnt)
   {
       cout << it.first << " " << it.second<< '\n';
   }

    return 0;
}



/* Question : https://practice.geeksforgeeks.org/problems/twice-counter4236/1
Company : Amazon 
Topic : map function ;

Code .... */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int count = 0;
        vector<string>v(n);
        for ( int i = 0 ;i < n ; i++)
        {
            cin>> v[i];
        }

        map< string,int > fre;
        for ( auto it : v)
        {
            fre[it]++;
        }

        for ( auto it : fre)
        {
            if ( it.second == 2)
            {
                count++;
            }
        }

        cout << count << '\n';

    }
  return 0;

}




/* Question :https://practice.geeksforgeeks.org/problems/word-with-maximum-frequency0120/1
Company : Amazon 
Topic : map function ;

Code .... */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore(); // getline use korle  cin.ignore dite hobe 
    while (t--)
    {
        string s ;
        getline( cin, s);

        string temp;
        vector<string>v;

        for (auto it : s )
        {
            if ( isspace(it)) // isspace mane space thakle kaj korbe 
            {
                v.push_back(temp); 
                v.empty();
            }
            else
            {
                temp = temp + it ;
            }
        }
        v.push_back(temp); // last word ta input newa 

        int max_frq = 0;

        map<string,int>frq;
        for ( auto it : v )
        {
            frq[it]++;
            max_frq = max( max_frq ,frq[it] );
        }

        string ans ;
        for ( auto it : v )
        {
            if (frq[it] == max_frq  )
                ans = it ;
            break;
        }

        cout << ans << " " << max_frq << '\n';


    }

    return 0;
}




/* Question :https://atcoder.jp/contests/arc087/tasks/arc087_a
code.... */

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    vector <int> v(n);
    for ( int i =  0;i< n;i++)
    {
        cin>>v[i];
    }

    map<int,int >frq ;

    for (auto it : v )
    {
        frq[it]++;
    }

    int  ans = 0;

    for (auto it : frq)
    {
        if ( it.second >= it.first)
        {
            ans = ans + (it.second - it.first);
        }
        else
        {
            ans = ans + it.second;
        }
    }

    cout << ans << '\n';

     return 0;
}


/* Question :https://codeforces.com/contest/855/problem/A
code.... */

#include<bits/stdc++.h>
using namespace std;
int main()
{
 
   int t;
   cin>>t;
 
   map<string,bool>check;  // primary sob string true (0)
 
   while (t--)
   {
       string s;
       cin>>s;
 
 
       if ( check[s] == 1)
       {
           cout << "YES" << '\n';
       }
       else
       {
           cout << "NO" << '\n';
       }
        check[s] = 1;    // loop ses e string 1 na pele oi string take 1 kore dewa hoy
                         // jeno porer bar buja jay je eta ekbar count hoyche .
   }
     return 0;
}



/* Question :https://codeforces.com/contest/4/problem/C
code.... */

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
 
    map<string, int> frq; // Use a map to store the count for each string || frq(frequency)
 
    while (t--)
    {
        string s;
        cin >> s;
 
        if (frq[s] == 0)  // 0 built in thake 
        {
            cout << "OK" << '\n';
        }
        else
        {
            cout << s << frq[s] << '\n';  // 0 na hole string and count digit print hobe 
        }
        frq[s]++; // poro loop ses hole 1 kore increment korbo 
    }
 
    return 0;
}

/* Question :https://codeforces.com/contest/918/problem/B
code.... */

#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,x ;
    cin>>n>>x;

    map<string,string>ipName;

    for (int i = 0;i < n;i++)
    {
       string name,ip;
       cin>>name>>ip;
       ipName[ip] = name;   // ip ta name e convert hoye jay ;

    }

    while ( x--)
    {
        string s1 , ip;
        cin>>s1>>ip;
        ip.pop_back();

        cout << s1 << " " << ip << "; #" << ipName[ip] << '\n';  // ipName[ip] er vitor ip ta paste korar jonno
                                                                  // last er ";" ta pop_back() kora hoyeche 
    }



    return 0;
}


/* Question :https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbjlMVVhBNjBmZzlGeGJSU25VY2xpX1BQeDBUZ3xBQ3Jtc0tueDFQeGxDWXZtMmxlcjRBclp0WWdYaVpIc0g5MkVUR05XT2NlWElhbklOYVFvNGE2SGwxQWZ1ZmNnUzN5c3pOYVlzV3djcWtlOHNKWjdlRVVWUDlONkFZaGZNUmhuQWZWZHA4eWFjRTloV05paEVXYw&q=https%3A%2F%2Fwww.spoj.com%2Fproblems%2FRPLD%2F&v=TQAGOHEK28Q
code.... */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, r;
        cin >> n >> r;
        map<pair<int, int>, bool> vis;
        bool seen = 1;

        while (r--) {
            int id, code;
            cin >> id >> code;

            if (vis[{id, code}]) // Check if the pair has been visited before
                seen = 0;        // If visited, set 'seen' to 0 (false)

            vis[{id, code}] = 1; // Mark the pair as visited (normally 1 means unvisited)
        }

        if (seen == 1)
            cout << "Scenario #" << tc << ": possible" << '\n';
        else
            cout << "Scenario #" << tc << ": impossible" << '\n';
    }

    return 0;
}


/* Question : https://codeforces.com/contest/1883/problem/B
code.... */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k;
    string s;
    cin >> t;
 
    while (t--)
    {
        map<char, int> mp;  // map < key , value > 
        cin >> n >> k >> s;
 
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
 
        int cnt = 0;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (mp[c] % 2 == 1)
                cnt++;
        }
 
        if (k < cnt - 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}


// Some online judge question :
1. https://codeforces.com/problemset/problem/782/A