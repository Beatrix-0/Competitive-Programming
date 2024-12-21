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

void insert_tail(int val )
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
        node *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = temp;
        temp->prev = tail;
    }
}

void delete_tail()
{
    if (head != nullptr)
    {
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        node *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->prev->next = nullptr;

        delete tail;
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

    insert_tail(80);
    display();

    delete_tail();
    display();

    return 0;
}
