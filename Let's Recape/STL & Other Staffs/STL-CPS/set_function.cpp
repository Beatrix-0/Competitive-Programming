// Video link : 1. https://youtu.be/cH_w5xNGEco?si=9XaGU9wj5DamgdPv 2. https://youtu.be/IQtdw37KV2I?si=nv0DpnBq5Qmq2HWb


// Question : https://www.hackerrank.com/challenges/cpp-sets/problem
#include<bits/stdc++.h>
using namespace std ;
int main ()
{
    set<int> s ;
    int t;
    cin>>t;
    while (t--)
    {
        int type, x;
        cin>>type >>x ;
        if ( type == 1 )
        {
            s.insert(x);
        }
        else if (type == 2)
        {
            s.erase (x);
        }
        else
        {
            if (s.count(x) == 1 ) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }

    return 0;
}



// Question :https://practice.geeksforgeeks.org/problems/c-stl-set-6-set/1


#include <bits/stdc++.h>
using namespace std;

void insert(set<int> &s,int x) /*inserts an element x to the set s */
{
    s.insert(x);
   
}


void print_contents(set<int> &s) /*prints the contents of the set s */
{
    for ( auto it : s) cout << it << " ";
}

void erase(set<int> &s,int x) /*erases an element x from the set s */
{
    s.erase(x);
}


int find(set<int> &s,int x) /*returns 1 if the element x is
                            present in set s else returns -1 */
{
    if ( s.count(x) ==1 ) return 1;
    else return -1;
}


int size(set<int> &s) /*returns the size of the set s */
{
  s.size();
}

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		set<int> s;
		int q;
		cin>>q;
		while(q--)
		{
			char c;
			cin>>c;
			if(c=='a')
			{
				int x;
				cin>>x;
				insert(s,x);
			}
			if(c=='b')
			{
				print_contents(s);
			}
			if(c=='c')
			{
				int x;
				cin>>x;
				erase(s,x);
			}
			if(c=='d')
			{
				int x;
				cin>>x;
				cout<<find(s,x)<<" ";
			}
             if(c=='e')
             cout<<size(s)<<" ";
		
		}
cout<<endl;
	}
	return 0;
}



// Question :https://practice.geeksforgeeks.org/problems/set-operations/1


#include <bits/stdc++.h>
using namespace std;

//User function Template for C++

set<int> setInsert(int arr[],int n) //Function to insert elements of array into a set and return a set
{
    set<int>s;
    
    for ( int i = 0 ; i< n ;i++) 
     s.insert(arr[i]) ;
    
    return s;
    
}


void setDisplay(set<int>s) //function to print the elements of the set
{
    for ( auto it : s ) cout << it << " ";
    cout<<endl;
}


void setErase(set<int>&s,int x) //function to erase x from set if it exists
{
   if ( s.count(x)==1) 
   {
       s.erase(x); cout << "erased " << x;
   }
   else 
   {
       cout << "not found";
   }
  
    cout<<endl;
}

// Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i]; 
        
        set<int>s=setInsert(arr,n); //call the insert function that returns a set
        setDisplay(s);         // display the inserted set
        int x;
        cin>>x; //x element that needs to be erased from set
        
        setErase(s,x); //try to erase x from set
        setDisplay(s); //print the set after erase operation
        
        
    }
	return 0;
}



// Question : https://codeforces.com/problemset/problem/469/A

#include<bits/stdc++.h>
using namespace std ;
int main ()
{
    set < int > s ;
    int n;
    cin>>n;

    int p ,q ;
    cin>>p;
    for ( int i = 0 ;i< p ;i++)
    {
        int a ;
        cin>>a ;
        s.insert(a);
    }
    cin>>q ;
    for ( int i = 0 ;i< q ;i++)
    {
        int b;
        cin>>b;
        s.insert(b);
    }

    if ( s.size() == n) cout << "I become the guy." << '\n';
    else cout << "Oh, my keyboard!" << '\n';

    return 0;
}

// Question : https://codeforces.com/problemset/problem/22/A

#include<bits/stdc++.h>
using namespace std ;
int main ()
{
    set< int > s ;
    int n;
    cin>> n;
     for ( int i = 0 ;i< n ;i++)
     {
         int a ;
         cin>>a ;
         s.insert(a);
     }

     if (s.size()<=1)
     {
         cout << "NO" << '\n';
     }
     else
     {
         cout << *( ++s.begin() ) << '\n';
     }


    return 0;
}


