#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *last = NULL;

void insert_val(int val)
{
    node *temp = new node();
    temp->data = val;

    if (last == NULL)
    {
        last = temp;
        last->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp ;
    }
}

void display()
{
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    node *cur = last->next;
    while (true)
    {
        cout << cur->data << " ";
        cur = cur->next;
        if (cur == last->next) break;
    }
    cout << '\n';
}

int main()
{
    insert_val(10);
    insert_val(185);
    insert_val(78);
    insert_val(91);

    cout << "Circular Linked List:" << '\n';
    display();

    return 0;
}
