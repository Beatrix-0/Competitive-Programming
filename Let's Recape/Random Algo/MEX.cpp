#include <bits/stdc++.h>
using namespace std;

void initialize(vector<int>& v, map<int, int>& mp, set<int>& missing_numbers) {
    int n = v.size();
    for (int i = 0; i <= n; i++)
        missing_numbers.insert(i);

    for (auto it : v) {
        mp[it]++;
        missing_numbers.erase(it);
    }
}

int get_mex(const set<int>& missing_numbers) {
    return *missing_numbers.begin();
}

void update(vector<int>& v, map<int, int>& mp, set<int>& missing_numbers, int idx, int val) {
    if (--mp[v[idx]] == 0)
        missing_numbers.insert(v[idx]);

    v[idx] = val;
    mp[val]++;
    missing_numbers.erase(val);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map<int, int> mp;
    set<int> st; // Missing numbers

    initialize(v, mp, st);

    cout << "Initial mex: " << get_mex(st) << '\n';
    update(v, mp, st, 2, 2); // Update index 2 to value 2
    cout << "Mex after update: " << get_mex(st) << '\n';

    return 0;
}
