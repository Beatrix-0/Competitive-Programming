#include <bits/stdc++.h> //     Space : O(N / 8)
using namespace std;

const int mx = 1e8;
int status[mx/32 + 5];
vector<int> prime;

bool check(int n, int pos) {
    return (bool)(n & (1 << pos));
}
int mark(int n, int pos) {
    return n = (n | (1 << pos));
}
void bitwiseSieve() {

    for (int i = 3; i*i <= mx; i += 2) {
        if (check(status[i/32], i % 32) == 0) {
            for (int j = i * i; j <= mx; j += 2 * i) {
                status[j/32] = mark(status[j/32], j % 32);
            }
        }
    }

    prime.push_back(2);
    for (int i = 3; i <= mx; i += 2) {
        if (check(status[i/32], i % 32) == 0) {
            prime.push_back(i);
        }
    }
}

int main() {
    bitwiseSieve();

    cout << prime.size() << '\n';
    // for ( auto it : prime ){
    //     cout << it << ' ';
    // }
    // cout << '\n';

    return 0;
}

// Time complexity is same as normal sieve , space complexity is optimal