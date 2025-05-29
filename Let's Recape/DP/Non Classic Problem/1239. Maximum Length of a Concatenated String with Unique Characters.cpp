// Problem : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

// Code Leetcode formate :
class Solution {
public:
    unordered_map<string, int> dp;
    vector<string> v;
    int n;

    bool isCheck(const string &a, const string &b) {
        int cnt[26] = {0};

        for (char c : a) {
            if (++cnt[c - 'a'] > 1) return true;  // Duplicate in a
        }

        for (char c : b) {
            if (cnt[c - 'a'] > 0) return true;  // Overlap with b
        }

        return false;
    }

    int yo(string tmp, int pos) {
        if (pos >= n) return tmp.size();

        string key = tmp + "|" + to_string(pos);
        if (dp.count(key)) return dp[key];

        int include = 0, exclude = 0;
        if (!isCheck(v[pos], tmp)) {
            include = yo(tmp + v[pos], pos + 1);
        }
        exclude = yo(tmp, pos + 1);

        return dp[key] = max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        v = arr;
        n = v.size();
        dp.clear();
        return yo("", 0);
    }
};


// Code Codeforces formate 
#include<bits/stdc++.h>
using namespace std ;

unordered_map<string , int>dp;
int n ; 
vector<string> v;

bool isCheck(string a , string b ){
    char cnt[26] = {0};
    for ( int i = 0 ; i < a.size() ; i++  ){
        if ( cnt[a[i] - 'a'] > 0 ) return true;
        cnt[a[i] - 'a']++;
    }

    for ( int i = 0 ; i < b.size() ; i++ ){
        if ( cnt[b[i] - 'a'] > 0 ){
            return true;
        }
    }

    return false;
}

int yo( string tmp , int pos ){
    if ( pos >= n ) return tmp.size();
    if ( dp.find(tmp) != dp.end()) return dp[tmp];

    int include = 0 ;
    int exclude = 0 ;
    if ( isCheck(v[pos] , tmp)){
        exclude = yo( tmp , pos+1);
    }
    else {
        exclude = yo( tmp , pos+1);
        include = yo( tmp+v[pos] , pos+1);
    }
    return dp[tmp] = max ( include , exclude);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc ; cin>> tc ;
    for ( int i = 1 ; i <= tc ; i++ ){
        v.clear();
        dp.clear();
        cin >> n ;
        v.resize(n);
        for ( int i = 0 ; i < n ; i++ ){
            cin >> v[i];
        }
       int mx_size  =  yo("" , 0);
       cout << mx_size << '\n';

    }
    
    return 0 ;
}

// Case : 
// 1
// 4
// un
// iq
// ue
// aa
// ans : 4 
