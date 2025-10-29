#include <bits/stdc++.h> // nloglogn
using namespace std;

const int MX = 5e6 + 10;
int pf_count[MX];
int pref[MX];

void precompute() {
    for (int i = 2; i < MX; i++) {
        if (pf_count[i] == 0) { 
            for (int j = i; j < MX; j += i) {
                int x = j;
                while (x % i == 0) {
                    pf_count[j]++;
                    x /= i;
                }
            }
        }
    }

    for (int i = 1; i < MX; i++) {
        pref[i] = pref[i - 1] + pf_count[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << pref[a] - pref[b] << '\n';
    }

    return 0;
}

// problem : https://codeforces.com/problemset/problem/546/D