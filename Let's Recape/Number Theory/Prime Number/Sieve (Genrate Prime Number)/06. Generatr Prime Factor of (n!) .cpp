// ...existing code...
#include <bits/stdc++.h>
using namespace std;

const int mx =100000000 ;
int spf[mx + 1];
vector<int> primes;

void SPF() {
    for (int i = 2; i <= mx; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || i * p > mx) break;
            spf[i * p] = p;
        }
    }
}

long long fact_pow(int n, int p) { //O(logn)
    long long res = 0;
    while (n) {
        n /= p;
        res += n;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SPF();

    int n ; cin >> n ;

    map<int,int>mp;
    for ( auto p : primes){
        if ( p > n ) break;
        int cnt = fact_pow( n , p);
        if ( p > 0 ){
            mp[p] = cnt ;
        }
    }

    for ( auto[p,e] : mp ){
        cout << p << " " << e << '\n';
    }

    return 0;
}