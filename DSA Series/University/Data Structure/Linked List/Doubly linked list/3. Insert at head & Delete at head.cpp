#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *head = nullptr;

void insert(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->next = nullptr;

    if (head == nullptr)
    {
        temp->prev = nullptr;
        head = temp;
    }
    else
    {
        node *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = temp;
        temp->prev = tail;
    }
}


void display()
{
    node *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << '\n';
}

void insert_head(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->next = nullptr;
    temp->prev = nullptr;

    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void delete_head()
{
    if (head != nullptr)
    {
        node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    insert(10);
    insert(20);
    insert(30);

    display();

    insert_head(80);
    display();

    delete_head();
    display();

    return 0;
}
