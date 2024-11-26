#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s ;
    cin>> s ;
    string target ;
    cin>> target ;
    string chk ;

    int cnt = 0 ;
    for ( int i = 0 ; i< target.size() ; i++ )  // target er soman substring niye nichi
                                                // etar sathe add and remove kore target er sathe compare korbo
    {
        chk = chk + s[i];
    }

    if ( chk == target)
    {
        cnt++;
    }

    for ( int i = target.size() ; i< s.size() ; i++ )
    {
        chk = chk + s[i];
        chk.erase( chk.begin());
        if ( chk == target )
        {
            cnt++;
        }
    }

    cout << cnt << '\n';
}

Practice problem :
1. https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
2. https://leetcode.com/problems/maximum-average-subarray-i/
3. https://codeforces.com/contest/1690/problem/D