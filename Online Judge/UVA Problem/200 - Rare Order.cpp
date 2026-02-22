#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "trace.cpp"
#else
#define dbg(...)
#endif

const int mx = 30;
vector<int>g[mx];
int indeg[mx];

void solve() {
    string s ; 
    vector<string>v;
    while (cin >> s ){
        if( s[0] == '#'){
            break;
        }
        else {
            v.push_back(s);
        }
    }
    int n = v.size();
    set<int>tmp;
    for ( int i = 1 ; i < n ; i++ ){
        string x = v[i-1];
        string y = v[i];
        int sz = min( x.size() , y.size());
        for(int i = 0 ; i < sz ; i++){
            if (x[i] != y[i]){
                int u = x[i] - 'A';
                int v = y[i] - 'A';
                tmp.insert(u);
                tmp.insert(v);
                g[u].push_back(v);
                indeg[v]++;
                break;
            }
        }
    }
    queue<int>q;
    for ( auto it : tmp ){
        if ( indeg[it] == 0 ){
            q.push(it);
        }
    }
    vector<int>ord;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ord.push_back(u);

        for( auto v : g[u]){
            indeg[v]--;
            if ( indeg[v] == 0 ){
                q.push(v);
            }
        }
    }

    for ( auto it : ord ){
        cout << char(it+'A');
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests = 1;
    // cin >> tests;
    for ( int tc = 1 ; tc <= tests ; tc++ ){
        solve();
    }
    return 0;
}