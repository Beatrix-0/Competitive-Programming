#include<bits/stdc++.h>
using namespace std ;

struct node{
    int o , z ;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc ; cin>> tc ;
    for ( int i = 1 ; i <= tc ; i++ ){
        int n , q ;
        cin >> n >> q ;
        vector<int> v(n+1);
        vector<int>tmp;
        for ( int i = 1 ; i <= n ; i++ ){
            cin >> v[i];
        }

        for ( int i = 2 ; i <= n ; i++ ){
            if( v[i] == v[i-1]){
                tmp.push_back(i-1);
            }
        }
        vector<node>pre(n+1 , {0,0});
        for ( int i = 1 ; i <= n ; i++ ){
            pre[i].o = pre[i-1].o + (v[i] == 1);
            pre[i].z = pre[i-1].z + (v[i] == 0);
        }

        while ( q-- ){
            int l , r ;
            cin >> l >> r ;
            int zero = pre[r].z - pre[l-1].z;
            int one = pre[r].o - pre[l-1].o;

            if( (zero%3 == 0) && (one %3 == 0) ){
                auto it = lower_bound(tmp.begin() , tmp.end() , l);
                int val = 1e9;
                if( it != tmp.end()){
                    val = *it;
                }
                
                if (val < r ){
                    int op = r-l+1;
                    cout << op/3 << '\n';
                }
                else {
                    int op = (r-l+1)-3 ;
                    cout << (op/3)+2 << '\n';
                }
            }else {
                cout << -1 << '\n';
            }
        }
    }
    
    return 0 ;
}
