[Problem](https://toph.co/p/maxxor)

```cpp
#include<bits/stdc++.h> // O(n*31)
using namespace std;

struct Trie{
    Trie* left;  //  0
    Trie* right; //  1
} * root;

Trie* Create(){
    Trie* node = new Trie();
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Insert(int n){
    Trie* cur = root;
    for (int i = 31; i >= 0; i--){
        int ith_bit = ((n >> i) & 1);
        if (ith_bit == 0){
            if (cur->left == NULL){
                cur->left = Create();
            }
            cur = cur->left;
        }
        else{
            if (cur->right == NULL){
                cur->right = Create();
            }
            cur = cur->right;
        }
    }
}

int yo(int x){
    int sum = 0;
    Trie* cur = root;
    for (int i = 31; i >= 0; i--){
        int ith_bit = ((x >> i) & 1);
        if (ith_bit == 0){
            if (cur->right != NULL){
                sum += (1 << i);
                cur = cur->right;
            }
            else{
                cur = cur->left;
            }
        }
        else{
            if (cur->left != NULL){
                sum += (1 << i);
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }
    }
    return sum;
}

int main(){
    root = Create();
    int n;
    cin >> n;
    vector<int> v(n);
    map < int , int > mp;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        Insert(v[i]);
        mp[v[i]] = i+1;
    }
    int mx = 0 , val = -1 ;
    int q ; cin>> q ;
    for (int i = 0; i < q; i++){
        int x ; cin>> x ;
        int mx = yo(x) ;
        int val = (x ^ val); // array te thakbe
       // cout << mx  << " " << val << '\n';
       cout << "Query " << i+1 << ": " << mp[val]  << " " << mx << '\n';
       mx = 0 ;
    }
    return 0;
}
```

## Maximum XOR of Two Numbers in an Array

```cpp
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "trace.cpp"
#else
#define dbg(...)
#endif

struct Trie {
    struct Node {
        Node* child[2];
        int cnt;

        Node() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int x) {
        Node* cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;

            if (!cur->child[bit])
                cur->child[bit] = new Node();

            cur = cur->child[bit];
            cur->cnt++;
        }
    }

    void remove(int x) {
        Node* cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;

            cur = cur->child[bit];
            cur->cnt--;
        }
    }

    int max_xor(int x) {
        Node* cur = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int want = 1 - bit;

            if (cur->child[want] && cur->child[want]->cnt > 0) {
                ans |= (1 << i);
                cur = cur->child[want];
            } else {
                cur = cur->child[bit];
            }
        }
        return ans;
    }
};

void solve() {
    Trie trie;
    trie.insert(0);

    int q ; cin >> q ;
    while (q--) {
        char type;
        int x;
        cin >> type >> x;

        if (type == '+') {
            trie.insert(x);
        }
        else if (type == '-') {
            trie.remove(x);
        }
        else { // '?'
            cout << trie.max_xor(x) << "\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests = 1;
    // cin >> tests;
    for ( int tc = 1 ; tc <= tests ; tc++ ){
        solve();
    }
    return 0;
}
```
