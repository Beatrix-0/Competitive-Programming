// Video link : https://youtu.be/7nSN1SM4fRs?si=e1wryjgsZd8DeEC_

// Question : https://practice.geeksforgeeks.org/problems/multiset-operations/1

#include <bits/stdc++.h>
using namespace std;


multiset<int> multisetInsert(int arr[],int n)
{
    multiset<int>s;
   for ( int i = 0 ;i< n; i++)
   {
       s.insert(arr[i]);
   }
    
    
    return s;
    
}


void multisetDisplay(multiset<int>s)
{
    for ( auto it : s) cout << it << ' ';
    cout<<endl;
}


void multisetErase(multiset<int>&s,int x)
{
    if ( s.count(x) == 0)
    {
        cout<<"not found";
    }
    else
    {
        s.erase(x);
        cout<<"erased "<<x;
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
        
        multiset<int>s=multisetInsert(arr,n); //call the insert function that returns a multiset
        multisetDisplay(s);// display the inserted multiset
        int x;
        cin>>x; //x element that needs to be erased from multiset
        
        multisetErase(s,x); //try to erase x from multiset
        multisetDisplay(s); //print the multiset after erase operation
        
        
    }
	return 0;
}