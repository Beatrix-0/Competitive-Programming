#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* head = nullptr;

void insert(int val)
{
    node* temp = new node();
    temp->data = val;
    temp->next = nullptr;
    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        node* tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = temp;
    }
}

void delete_pos(int x)
{
    if (x < 1 || head == nullptr) return;

    if (x == 1)
    {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node* cur = head;
    int cnt = 1;
    while (cnt < x - 1 && cur->next != nullptr)
    {
        cur = cur->next;
        cnt++;
    }

    if (cur->next != nullptr)
    {
        node* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
    }
}

void display()
{
    node* cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    display();  
    delete_pos(3);
    display();  

    return 0;
}
