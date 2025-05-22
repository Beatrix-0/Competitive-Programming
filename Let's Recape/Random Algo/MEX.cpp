#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;

vector<int> A;
map<int, int> freq;
set<int> missing;

void build(const vector<int>& v) { // nlogn (pre compute)
    A = v;
    freq.clear();
    missing.clear();

    int n = A.size();
    for (int i = 0; i <= n; i++) {
        missing.insert(i);
    }

    for (int x : A) {
        freq[x]++;
        missing.erase(x);
    }
}

int get() { // O(1)
    return *missing.begin();
}

void update(int idx, int new_val) { // logn 
    int old_val = A[idx];

    freq[old_val]--;
    if (freq[old_val] == 0) {
        missing.insert(old_val);
    }

    A[idx] = new_val;
    freq[new_val]++;
    missing.erase(new_val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    build(v);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            cout << get() << '\n';
        } else if (type == 2) {
            int idx, val;
            cin >> idx >> val;
            update(idx, val);
        }
    }

    return 0;
}
