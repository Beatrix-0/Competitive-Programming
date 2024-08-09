#include<bits/stdc++.h>
using namespace std;
int main()
{
    map < string , int > mp ;

    int m , n , taka ;
    cin>> m >> n ;

    string name ;

    while ( m-- )
    {
        cin>> name ;
        cin>> taka ;

        mp[name] = taka ;
    }

    while ( n-- )
    {
       unsigned long long int total_taka = 0 ;

       while ( cin >> name && name != ".")
       {
           total_taka = total_taka + mp[name];
       }

       cout << total_taka << '\n';
    }

    return 0 ;
}
