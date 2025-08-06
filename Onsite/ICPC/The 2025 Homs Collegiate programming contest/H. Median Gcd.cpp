#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int l, r; 
        cin>>l>>r;

        int n = r-l+1;
        int ans;
        if(l==r){
            ans = l;
        }else{
            ans = (n-2) + __gcd(l,r) + r;
        }
        cout<< ans <<'\n';
    }
    return 0;
}