#include <bits/stdc++.h>
using namespace std;

struct Trie // node
{
    int pref_cnt;
    bool isEnd;
    struct Trie *child[26];
} * root;

void Create()
{
    root = new Trie();
    root->pref_cnt = 0;
    root->isEnd = false;
    for (int i = 0; i < 26; i++)
        root->child[i] = NULL;
}

void Insert(string s)
{
    Trie *cur = root;
    cur->pref_cnt++;
    for (int i = 0; i < s.size(); i++)
    {
        int ind = s[i] - 'a';
        if (cur->child[ind] == NULL)
        {
            Trie *newNode = new Trie();
            newNode->pref_cnt = 0;
            newNode->isEnd = false;
            for (int j = 0; j < 26; j++)
                newNode->child[j] = NULL;
            cur->child[ind] = newNode;
        }
        cur->child[ind]->pref_cnt++;
        cur = cur->child[ind];
    }
    cur->isEnd = true;
}

bool Search(string s)
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

int word_with_pref(string pref)
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
    Create();

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
            cout << "No such prefix exists" << '\n';
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
*/
