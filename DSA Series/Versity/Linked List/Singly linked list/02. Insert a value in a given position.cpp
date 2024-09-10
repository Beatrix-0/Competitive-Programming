#include<bits/stdc++.h>
using namespace std ;

struct node
{
    int data ;
    node *next ;
};
node *head = nullptr;
void insert( int val )
{
    node *temp = new node();
    temp-> data = val ;
    temp->next = nullptr ;
    if ( head == nullptr )
    {
        head = temp ;
    }
    else
    {
        node *tail = head ;
        while ( tail->next != nullptr )
        {
            tail = tail->next;
        }
        tail -> next = temp;
    }
}

void insert_pos ( int x , int val )
{
    node *cur = head ;
    int cnt = 1 ;
    while ( cur->next != nullptr && cnt != x)
    {
        cnt++;
        cur = cur ->next ;
    }
    node *temp = new node();
    temp -> data = val ;
    if ( cur ->next != nullptr)
    {
        temp ->next = cur ->next ;
        cur-> next = temp ;
    }
}
void display()
{
    node *cur ;
    cur = head ;
    while ( cur != nullptr)
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

    // we can use for loop for user input as well
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    display();
    insert_pos(3 , 87);
    display();


    return 0 ;
}
