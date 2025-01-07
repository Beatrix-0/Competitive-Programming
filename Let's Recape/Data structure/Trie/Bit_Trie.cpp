#include<bits/stdc++.h> // O(n*31)
using namespace std;

struct Trie
{
    Trie* left;  //  0
    Trie* right; //  1
} * root;

Trie* Create()
{
    Trie* node = new Trie();
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Insert(int n)
{
    Trie* cur = root;
    for (int i = 31; i >= 0; i--)
    {
        int ith_bit = ((n >> i) & 1);
        if (ith_bit == 0)
        {
            if (cur->left == NULL)
            {
                cur->left = Create();
            }
            cur = cur->left;
        }
        else
        {
            if (cur->right == NULL)
            {
                cur->right = Create();
            }
            cur = cur->right;
        }
    }
}

int yo(int x)
{
    int sum = 0;
    Trie* cur = root;
    for (int i = 31; i >= 0; i--)
    {
        int ith_bit = ((x >> i) & 1);
        if (ith_bit == 0)
        {
            if (cur->right != NULL)
            {
                sum += (1 << i);
                cur = cur->right;
            }
            else
            {
                cur = cur->left;
            }
        }
        else
        {
            if (cur->left != NULL)
            {
                sum += (1 << i);
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
    }
    return sum;
}

int main()
{
    root = Create();
    int n;
    cin >> n;
    vector<int> v(n);
    map < int , int > mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        Insert(v[i]);
        mp[v[i]] = i+1;
    }
    int mx = 0 , val = -1 ;
    int q ; cin>> q ;
    for (int i = 0; i < q; i++)
    {
        int x ; cin>> x ;
        int mx = yo(x) ; 
        int val = (x ^ val); // array te thakbe
       // cout << mx  << " " << val << '\n';
       cout << "Query " << i+1 << ": " << mp[val]  << " " << mx << '\n';
       mx = 0 ;
    }

    return 0;
}
// Problem : https://toph.co/p/maxxor