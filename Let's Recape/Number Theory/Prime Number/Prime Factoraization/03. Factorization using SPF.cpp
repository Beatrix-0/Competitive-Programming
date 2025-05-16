#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6;
int spf[mx + 1];
vector<int> primes;
vector<int> g[mx + 1]; 

// Time Complexity: O(N log log N)
void computeSPF() {
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

// Time Complexity: O(log val)
vector<int> getPFactor(int val) {
    vector<int> tmp;
    while (val > 1) {
        int p = spf[val];
        tmp.push_back(p);
        while (val % p == 0) { // calculate frq from here 
            val /= p;
        }
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    computeSPF();

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        g[v[i]] = getPFactor(v[i]);
    }

    
    // for (int i = 0; i < n; i++) {
    //     cout << "Prime factors of " << v[i] << ": ";
    //     for (int p : g[v[i]]) {
    //         cout << p << " ";
    //     }
    //     cout << '\n';
    // }
    

    return 0;
}
