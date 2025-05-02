#include<bits/stdc++.h>
using namespace std ;

const int mx = 1e5+123;
int v[mx];
struct Node{
    int leftMost , rightMost , frLeftMost , frRightMost , ans;
    Node(){}
    Node ( int a , int b , int c , int d , int e ){
        leftMost = a ;
        rightMost = b;
        frLeftMost = c;
        frRightMost = d;
        ans = e ;
    }
};

struct Node t[mx*4];
struct Node merge(struct Node leftNode , struct Node rightNode){
    if( leftNode.ans == 0 ) return rightNode;
    if( rightNode.ans == 0 ) return leftNode;
    struct Node cur ;
    cur.leftMost = leftNode.leftMost;
    cur.rightMost = rightNode.rightMost;
    if ( leftNode.leftMost == rightNode.rightMost){
        int tmp = leftNode.frLeftMost + rightNode.frRightMost;
        cur.frLeftMost = tmp ;
        cur.frRightMost = tmp;
        cur.ans = tmp ;
    }
    else if ( leftNode.leftMost == rightNode.leftMost){
        cur.frLeftMost = leftNode.frLeftMost + rightNode.frLeftMost;
        cur.frRightMost = rightNode.frRightMost;
        cur.ans = max(cur.frLeftMost , rightNode.ans);
    }
    else if ( leftNode.rightMost == rightNode.rightMost){
        cur.frLeftMost = leftNode.frLeftMost;
        cur.frRightMost = leftNode.frRightMost + rightNode.frRightMost;
        cur.ans = max( leftNode.ans , cur.frRightMost);
    }
    else if( leftNode.rightMost == rightNode.leftMost){
        cur.frLeftMost = leftNode.frLeftMost;
        cur.frRightMost = rightNode.frRightMost;
        cur.ans = max({leftNode.ans , rightNode.ans , leftNode.frRightMost + rightNode.frLeftMost});
    }
    else {
        cur.frLeftMost = leftNode.frLeftMost;
        cur.frRightMost = rightNode.frRightMost;
        cur.ans = max(leftNode.ans , rightNode.ans);
    }
    return cur;
}

void build ( int node , int b , int e ){
    if ( b == e ){
        t[node].leftMost = v[b];
        t[node].rightMost = v[b];
        t[node].frLeftMost = 1 ;
        t[node].frRightMost = 1 ;
        t[node].ans = 1 ;
        return ;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    build(left , b , mid );
    build(right , mid+1 , e );
    t[node] = merge(t[left] , t[right]);
}

struct Node query( int node , int b , int e , int i , int j ){
    if ( b > j or e < i ) {
        return Node(0,0,0,0,0);
    }
    if (b >= i && e <= j ){
        return t[node];
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    struct Node p1 = query(left , b , mid , i , j );
    struct Node p2 = query(right , mid+1 , e , i , j );
    return merge(p1 , p2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    while (cin >> n)
    {
        if (n == 0) break;
        cin >> q;
        for (int i = 1; i <= n; i++){
            cin >> v[i];
        }
        build(1, 1, n );
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1,1,n,l,r).ans << '\n';
        }
    }
    return 0;
}
