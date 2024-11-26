#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    // Constructor to initialize data and next
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* node_1 = new Node(4);

    cout << node_1->data << " " << node_1->next << '\n'; // node_1->data == (*node_1).data

    delete node_1; // Free the allocated memory

    return 0;
}
