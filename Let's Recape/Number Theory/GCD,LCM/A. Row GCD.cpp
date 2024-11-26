// Problem : https://codeforces.com/problemset/problem/1458/A

#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n), q(m);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> q[i];
    }
    
    /* 
    gcd( a , b ) = gcd ( a , a-b)  
    similarly, gcd ( a , b , c...) = gcd ( a , a-b , a-c ....)  
    after adding any value x 
       - gcd ( a+x , b+x , c+x...) = gcd ( a+x , a+x(-b+x) , a+x(-c+x) ....)  
       - gcd ( a+x , b+x , c+x...) = gcd ( a+x , a-b , a-c ....)  
       - gcd ( a+x , b+x , c+x...) = gcd ( a+x ,gcd ( a-b , a-c ....))
       
    */   
    
    int x = 0;
    for (int i = 1; i < n; i++) {
        x = __gcd(x, abs(v[i] - v[i-1]));
    }

    for (int i = 0; i < m; i++) {
        cout << __gcd(v[0] + q[i], x) << " ";
    }
    
    cout << '\n';
    return 0;
}
