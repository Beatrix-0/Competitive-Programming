// Topic 01 : Some basic function of a string 
//Code:
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    cout << s.size() << '\n';

    sort(s.begin(), s.end());
    cout << s << '\n';

    reverse(s.begin(), s.end());
    cout << s << '\n';

    string x = s.substr(0, 3); // Use s.substr() instead of substr()
    cout << x << '\n';

    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
    }

    cout << s << '\n';

    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }

    cout << s << '\n';

    s.clear(); // Use clear() instead of erase()
    cout << s << '\n';

    s.push_back('a'); // Use single quotes for characters
    s.push_back('b');
    s.push_back('c');

    cout << s << '\n';

    s.pop_back();
    cout << s << '\n';

    return 0;
}

/* 
strins s ;
getlie ( cin>> s );
cout << s ;

istringstream x (s);
string a ;
while ( x >> a )
{
    cout << a << '\n';
}
*/


------------------------------------------------------------------------------------------------------------------------------------------------

//Topic 02 : String to num and num to string 
//Code :
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s ;
    cin>> s ;
    int num = 0;

    // string to number//

    //manual code
    for ( int i = 0 ; i< s.size() ; i++ )
    {
        int x = s[i] - '0';
        num = ( num * 10 ) + x ;
    }
    cout << num << '\n';

    // builtin code
    int num_2 = stoi(s);
    cout << num_2 << '\n';


    // number to string //


    //manual code
    int num_3 = 2254;
    string ans ;
    while ( num_3 >= 0 )
    {
        int y = num_3%10;
        char ch = y + '0';
        ans = ans + ch;
        num_3/=10;
    }

    cout << ans << '\n';

    // builtin code

    string ans_2 = to_string(num_3);
    cout << ans_2 << '\n';



    return 0 ;
}

------------------------------------------------------------------------------------------------------------------------------------------------

//Topic 03 : Next permutation :
//Code:
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // for string
    string s;
    cin >> s;
    set<string> st;
    sort(s.begin(), s.end());
    st.insert(s);

    while (next_permutation(s.begin(), s.end()))
    {
        st.insert(s);
    }

    for (auto it : st)
    {
        cout << it << '\n';
    }

    // for digits
    vector<int> v = {1, 2, 3};

    do
    {
        for (int i = 0; i < 3; i++)
        {
            cout << v[i] << " ";
        }
        cout << '\n';
    }
    while (next_permutation(v.begin(), v.end()));

    return 0;
}

Practice problem :
1. https://cses.fi/problemset/task/1622

------------------------------------------------------------------------------------------------------------------------------------------------
