#include<bits/stdc++.h>
using namespace std ;

struct Stack{
  int top;
  int stack_sz;
  int *item; // array
};

Stack *create(int sz)
{
   Stack *pt = new Stack();

   pt->top = -1;
   pt->stack_sz = sz;
   pt->item = new int[sz]; 

   return pt;
}

bool isEmpty(Stack *pt)
{
    return pt->top == -1; 
}

bool isFull(Stack *pt)
{
    return pt->top == pt->stack_sz - 1; 
}

void push(int val, Stack *pt)
{
    if (!isFull(pt))
    {
        pt->top++;
        pt->item[pt->top] = val;
    }
    else
    {
        cout << "Cannot push..stack is full\n";
    }
}

void pop(Stack *pt)
{
    if (!isEmpty(pt))
    {
        pt->top--;
    }
    else
    {
        cout << "Cannot pop..stack is empty\n";
    }
}

void peek(Stack *pt)
{
    if (!isEmpty(pt))
    {
        cout << pt->item[pt->top] << '\n';
    }
    else
    {
        cout << "Cannot display..stack is empty\n";
    }
}

void display(Stack *pt)
{
    if (!isEmpty(pt))
    {
        for (int i = pt->top; i >= 0; i--)
        {
            cout << pt->item[i] << " ";
        }
        cout << '\n';
    }
    else
    {
        cout << "Cannot display..stack is empty\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Stack *st = create(5);

    if (isEmpty(st)) cout << "Empty\n";
    else cout << "Not Empty\n";

    if (isFull(st)) cout << "Full\n";
    else cout << "Not Full\n";

    push(3, st);
    push(7, st);
    peek(st);
    display(st);

    pop(st);
    peek(st);
    display(st);

    return 0;
}
