#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    // Constructor
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

// Function to insert a new node at the tail of the list
void insertAtTail(Node*& head, Node*& tail, int d)
{
    Node* temp = new Node(d);
    if (tail == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

// Function to print the linked list
void print(Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtTail(head, tail, 10);
    print(head);

    insertAtTail(head, tail, 12);
    print(head);

    insertAtTail(head, tail, 47);
    insertAtTail(head, tail, 28);
    print(head);

    return 0;
}
