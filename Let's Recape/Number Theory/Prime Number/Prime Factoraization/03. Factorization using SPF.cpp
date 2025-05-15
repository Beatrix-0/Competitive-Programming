#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6;
int spf[mx + 1];    
vector<int> primes;  

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

// Prime factorization using precomputed SPF
// Time Complexity: O(log n)
unordered_map<int, int> getPrimeFactors(int x) {
    unordered_map<int, int> count;
    while (x > 1) {
        int p = spf[x];
        count[p]++;
        x /= p;
    }
    return count;
}

int main() {
    computeSPF();

    int num = 100;
    auto factors = getPrimeFactors(num);

    cout << "Prime factorization of " << num << ":\n";
    for (auto [p, freq] : factors) {
        cout << p << "^" << freq << "\n";
    }

    return 0;
}
