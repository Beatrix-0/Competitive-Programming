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

void remove_tail( )
{
   if ( head != nullptr)
   {
       node *cur = head ;
       while ( cur->next->next != nullptr )
       {
           cur = cur->next ;
       }
       cur->next = nullptr ;

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
    cout << head ->next -> next ->data << '\n';
    remove_tail( );
    display();

    return 0 ;
}
