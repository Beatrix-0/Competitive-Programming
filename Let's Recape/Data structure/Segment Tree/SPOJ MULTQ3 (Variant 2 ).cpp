#include<bits/stdc++.h>
using namespace std;

const int mx = 1e5+123;

struct Node {
    int x; // val % 3 == 0 
    int y; // val % 3 == 1 
};

Node t[4*mx];
int lazy[4*mx];

void propagate(int node, int b, int e) {
    lazy[node] %= 3;
    int s0 = t[node].x; // remainder 0 
    int s1 = t[node].y; // remainder 1
    int s2 = (e - b + 1) - s0 - s1; // remainder 2
    if (lazy[node] == 0) return;
    else if (lazy[node] == 1) {
        t[node].x= s2 ; 
        t[node].y = s0 ;
    }
    else {
        t[node].x= s1 ; 
        t[node].y = s2 ;
    }
    if (b != e) {
        int left = node * 2;
        int right = node * 2 + 1;
        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
    }
    lazy[node] = 0;
}

Node merge(Node leftNode, Node rightNode) {
    Node ans;
    ans.x = leftNode.x + rightNode.x;
    ans.y = leftNode.y + rightNode.y;
    return ans;
}

void build(int node, int b, int e) {
    lazy[node] = 0;
    if (b == e) {
        t[node] = {1, 0};
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    t[node] = merge(t[left], t[right]);
}

void upd(int node, int b, int e, int i, int j) {
    propagate(node, b, e);
    if (j < b || i > e) return;
    if (i <= b && e <= j) {
        lazy[node] += 1;
        propagate(node, b, e);
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    upd(left, b, mid, i, j);
    upd(right, mid + 1, e, i, j);
    t[node] = merge(t[left], t[right]);
}

Node query(int node, int b, int e, int i, int j) {
    propagate(node, b, e);
    if (j < b || i > e) return {0, 0};
    if (i <= b && e <= j) {
        return t[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    Node p1 = query(left, b, mid, i, j);
    Node p2 = query(right, mid + 1, e, i, j);
    return merge(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    build(1, 1, n);
    while (q--) {
        int x, l, r;
        cin >> x >> l >> r;
        l++;r++;
        if (x == 0) {
            upd(1, 1, n, l, r);
        } else {
            Node res = query(1, 1, n, l, r);
            cout << res.x << '\n';  
        }
    }

    return 0;
}
