#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

bool isEmpty(Node* last)
{
    return last == nullptr;
}

Node* enqueue(Node* last, int value)
{
    Node* temp = new Node();
    temp->data = value;
    if (isEmpty(last))
    {
        temp->next = temp;
        last = temp;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    return last;
}

Node* dequeue(Node* last)
{
    if (isEmpty(last) || last->next == last)
    {
        if (last)
        {
            delete last->next;
        }
        return nullptr;
    }
    Node* temp = last->next;
    last->next = temp->next;
    delete temp;
    return last;
}

int top(Node* last)
{
    if (isEmpty(last))
        return -1;
    return last->next->data;
}

void displayQueue(Node* last)
{
    if (isEmpty(last))
        return;
    Node* temp = last->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while (temp != last->next);
    cout << endl;
}

int main()
{
    Node* last = nullptr;
    last = enqueue(last, 10);
    last = enqueue(last, 20);
    last = enqueue(last, 30);
    displayQueue(last);
    last = dequeue(last);
    displayQueue(last);
    cout << "Front element: " << top(last) << endl;
    last = dequeue(last);
    last = dequeue(last);
    last = dequeue(last);
    cout << "Queue empty: " << isEmpty(last) << endl;
    return 0;
}
