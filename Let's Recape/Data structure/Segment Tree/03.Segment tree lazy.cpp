#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 123;
int v[mx], t[4 * mx], lazy[4 * mx];

void propagate(int node, int b, int e) {
    if (lazy[node] != 0) {
        // Apply the pending update
        t[node] += lazy[node] * (e - b + 1);
        if (b != e) {
            int left = node * 2;
            int right = node * 2 + 1;
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
}

int combine(int a, int b) {
    return a + b; // For sum queries
}

void merge(int node) {
    int left = node * 2;
    int right = node * 2 + 1;
    t[node] = combine(t[left], t[right]);
}

void build(int node, int b, int e) {
    lazy[node] = 0;
    if (b == e) {
        t[node] = v[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    merge(node);
}

void upd(int node, int b, int e, int i, int j, int val) {
    propagate(node, b, e);
    if (j < b || i > e) return;
    if (i <= b && e <= j) {
        lazy[node] = val;
        propagate(node, b, e);
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    upd(left, b, mid, i, j, val);
    upd(right, mid + 1, e, i, j, val);
    merge(node);
}

int query(int node, int b, int e, int i, int j) {
    propagate(node, b, e);
    if (j < b || i > e) return 0;
    if (i <= b && e <= j) {
        return t[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    return combine(query(left, b, mid, i, j), query(right, mid + 1, e, i, j));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    build(1, 1, n);

    cout << query(1, 1, n, 2, 4) << '\n'; // Initial sum from 2 to 4
    upd(1, 1, n, 2, 5, 10);               // Add 10 to range [2, 4]
    cout << query(1, 1, n, 2, 5) << '\n'; // New sum from 2 to 4

    return 0;
}
