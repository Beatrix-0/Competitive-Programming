// Video link : https://youtu.be/FRJrfCjC2GY?si=zppXhE3M9moNUQMk

// Question : https://practice.geeksforgeeks.org/problems/special-stack/1
#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}// } Driver Code Ends


/*Complete the function(s) below*/
void push(int a)
{
     s.push (a);
}

bool isFull(int n)
{
     return n == s.size();
}

bool isEmpty()
{
    return s.empty();
}

int pop()
{
    s.pop();
}

int getMin()
{
    int mn = 2e9;
    
    while ( !s.empty() ) {
        mn = min ( s.top(), mn );
        s.pop();
    }
    
    return mn;
}