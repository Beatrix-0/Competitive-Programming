#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int sz;
    int front;
    int rear;
    int occupied;
    int *item;
};

Queue *create(int n)
{
    Queue *pt = new Queue();
    pt->sz = n;
    pt->front = 0;
    pt->rear = 0;
    pt->occupied = 0;
    pt->item = new int[n];
    return pt;
}

bool isFull(Queue *pt)
{
    return pt->sz == pt->occupied;
}

bool isEmpty(Queue *pt)
{
    return pt->occupied == 0;
}

void enqueue(Queue *pt, int val)
{
    if (!isFull(pt))
    {
        pt->item[pt->rear] = val;
        pt->rear = (pt->rear + 1) % pt->sz;
        pt->occupied++;
    }
    else
    {
        cout << "Queue is Full" << '\n';
    }
}

void dequeue(Queue *pt)
{
    if (!isEmpty(pt))
    {
        pt->front = (pt->front + 1) % pt->sz;
        pt->occupied--;
    }
    else
    {
        cout << "Queue is Empty" << '\n';
    }
}

void top(Queue *pt)
{
    if (!isEmpty(pt))
    {
        cout << pt->item[pt->front] << '\n';
    }
    else
    {
        cout << "Queue is Empty" << '\n';
    }
}

int main()
{
    Queue *q1 = create(5);
    enqueue(q1, 10);
    enqueue(q1, 20);
    top(q1);
    dequeue(q1);
    dequeue(q1);
    dequeue(q1);

    delete[] q1->item;
    delete q1;

    return 0;
}
