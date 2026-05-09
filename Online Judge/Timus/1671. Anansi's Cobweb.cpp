
// JUDGE_ID: 369592GY

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int mx = 2e5+123;
struct Disjoint_set_union{
    int Parent[mx], Size[mx];
    void Init(int n){
        for (int i = 0; i <= n; i++){
            Parent[i] = i;
            Size[i] = 1;
        }
    }
    int Find(int v){
        if (v == Parent[v]) return v;
        return Parent[v] = Find(Parent[v]);
    }
    bool Union(int u, int v){
        int root_u = Find(u);
        int root_v = Find(v);
        if (root_u != root_v){
            if (Size[root_u] < Size[root_v]){
                swap(root_u, root_v);
            }
            Parent[root_v] = root_u;
            Size[root_u] += Size[root_v];
            return true; 
        }
        return false;
    }
} dsu;

void solve() {
    int n , m ;
    cin >> n >> m ;
    dsu.Init(n);
    vector<pair<int,int> >p;
    map<int,pair<int,int> >mp;
    for ( int i = 0 ; i < m ; i++ ){
        int u , v ;
        cin >> u >> v ;
        p.push_back(make_pair(u , v));
        mp[i+1] = make_pair(u,v);
    }
    int q ; cin >> q ;
    vector<int>cnt(m) , ord;
    for ( int i = 0 ; i < q ; i++ ){
        int x ; cin >> x ;
        ord.push_back(x);
        cnt[x-1] = 1 ;
    }
    for ( int i = 0 ; i < m ; i++ ){
        if (!cnt[i]){
            dsu.Union(p[i].first , p[i].second);
        }
    }

    set<int>s;
    for ( int i = 1 ; i <= n ; i++ ){
        s.insert(dsu.Find(i));
    }
    int cmp = s.size();
    vector<int>ans;
    for ( int i = q-1 ; i >= 0 ; i-- ){
        int id = ord[i];
        pair<int,int> uv = mp[id];
        int u = uv.first , v = uv.second;
        ans.push_back(cmp);
        
        int a = dsu.Find(u);
        int b = dsu.Find(v);
        if ( a != b ){
            cmp--;
        }
        dsu.Union(u, v);
    }
    reverse(ans.begin() , ans.end());
    for (int i = 0; i < (int)ans.size(); i++){
        cout << ans[i];
        if (i < (int)ans.size()-1) cout << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}