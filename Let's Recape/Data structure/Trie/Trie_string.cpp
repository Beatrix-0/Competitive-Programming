#include <bits/stdc++.h> // O ( n * L )
using namespace std;

struct Trie // node
{
    int pref_cnt;
    bool isEnd;
    struct Trie *child[26];
} * root;

Trie *Create()
{
    Trie *node = new Trie();
    node->pref_cnt = 0;
    node->isEnd = false;
    for (int i = 0; i < 26; i++)
        node->child[i] = NULL;
    return node;
}

void Insert(string s) // O( n*L) L = string length
{
    Trie *cur = root;
    cur->pref_cnt++;
    for (int i = 0; i < s.size(); i++)
    {
        int ind = s[i] - 'a';
        if (cur->child[ind] == NULL)
        {
            Trie *newNode = Create();
            cur->child[ind] = newNode;
        }
        cur->child[ind]->pref_cnt++;
        cur = cur->child[ind];
    }
    cur->isEnd = true;
}

bool Search(string s) // O( q1*L)
{
    Trie *cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        int ind = s[i] - 'a';
        if (cur->child[ind] == NULL)
        {
            return false; // not found
        }
        cur = cur->child[ind];
    }
    return cur->isEnd;
}

int word_with_pref(string pref) // O( q2*L)
{
    Trie *cur = root;
    for (int i = 0; i < pref.size(); i++)
    {
        int ind = pref[i] - 'a';
        if (cur->child[ind] == NULL)
        {
            return 0;
        }
        cur = cur->child[ind];
    }
    return cur->pref_cnt;
}

int main()
{
    root = Create();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        Insert(s);
    }

    int q1;
    cin >> q1;
    while (q1--)
    {
        string x;
        cin >> x;
        if (Search(x))
        {
            cout << "found it!" << '\n';
        }
        else
        {
            cout << "Not found!" << '\n';
        }
    }

    int q2;
    cin >> q2;
    while (q2--)
    {
        string y;
        cin >> y;
        int count = word_with_pref(y);
        if (count == 0)
        {
            cout << "No complete word starts with it" << '\n';
        }
        else
        {
            cout << "No of words with same prefix: " << count << '\n';
        }
    }

    return 0;
}
/*
5
siam ahmed fahim khan emad
3
juton siam emad
3
sia ah mh

problem :  https://www.spoj.com/problems/ADAINDEX/
*/
