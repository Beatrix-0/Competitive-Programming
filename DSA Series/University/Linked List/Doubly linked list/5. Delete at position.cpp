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

void delete_pos ( int ind )
{
    int cnt = 1;
    node *cur = head ;
    while ( cnt != ind )
    {
        cur = cur ->next ;
        cnt++;
    }

    cur ->next ->next ->prev = cur ;
    cur ->next = cur ->next ->next ;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();
    delete_pos(3);
    display();

    return 0;
}
