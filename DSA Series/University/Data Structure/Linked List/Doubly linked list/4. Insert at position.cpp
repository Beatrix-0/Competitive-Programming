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

void insert_pos ( int ind , int val )
{
    node *temp = new node();
    temp->data = val ;
    temp->prev = nullptr;
    temp->next = nullptr;
    int cnt = 1;
    node *cur = head ;
    while ( cnt != ind )
    {
        cur = cur ->next ;
        cnt++;
    }

    temp->next = cur->next ;
    temp->prev = cur ;
    cur ->next->prev = temp ;
    cur ->next = temp;
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
    insert_pos(3 , 75 );
    display();

    return 0;
}
