#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = nullptr;

void insert(int val) {
    node* temp = new node();
    temp->data = val;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
    } else {
        node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = temp;
    }
}

int count_element() {
    int cnt = 0;
    node* cur = head;
    while (cur != nullptr) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

void find_mid() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    int x = count_element();
    x = x/2;
    node *cur = head ;
    int cnt = 0 ;
    while ( cur ->next != nullptr && cnt != x )
    {
        cnt++;
        cur = cur -> next ;
    }
    cout << cur ->data << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);

    cout << count_element() << '\n';
    find_mid();

    return 0;
}
