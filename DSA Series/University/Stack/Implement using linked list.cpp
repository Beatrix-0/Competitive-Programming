#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = nullptr;

bool isEmpty()
{
    return head == nullptr; // Corrected: stack is empty if head is nullptr
}

void push(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->next = head;
    head = temp;
}

void pop()
{
    if (!isEmpty()) // Corrected: pop only when stack is not empty
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        cout << "Cannot pop..stack is empty" << '\n';
    }
}

void peek()
{
    if (!isEmpty()) // Corrected: peek only when stack is not empty
    {
        cout << head->data << '\n';
    }
    else
    {
        cout << "Cannot display..stack is empty" << '\n';
    }
}

void display()
{
    if (!isEmpty()) // Corrected: display only when stack is not empty
    {
        node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << '\n';
    }
    else
    {
        cout << "Cannot display..stack is empty" << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (isEmpty())
        cout << "Empty\n";
    else
        cout << "Not Empty\n";

    push(10);
    push(20);
    display();  // should display 20 10

    pop();      // removes 20
    display();  // should display 10

    peek();     // should display 10

    pop();      // removes 10
    display();  // should display "Cannot display..stack is empty"
    peek();     // should display "Cannot display..stack is empty"

    return 0;
}
