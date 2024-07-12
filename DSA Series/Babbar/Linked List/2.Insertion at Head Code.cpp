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

// Function to insert a new node at the head of the list
void insertAtHead(Node*& head, int d)
{
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Function to print the linked list
void print(Node*& head)
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

    Node* head = new Node(10);
    print(head);

    insertAtHead(head, 12);

    print(head);

    insertAtHead(head, 47);
    insertAtHead(head, 28);

    print(head);

    return 0;
}
