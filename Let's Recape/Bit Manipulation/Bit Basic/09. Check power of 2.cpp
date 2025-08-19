#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n; cin>>n;

   // way 01 
   int cnt = 0 ;
   for ( int i = 0 ; i< 31 ; i++ ){
       if ( n & 1){
           cnt++;
       }
       n = ( n >> 1 );
   }

   if ( cnt == 1 ){
       cout << "The input is power of 2" << '\n';
   }
   else{
       cout << "The input is not power of 2" << '\n';
   }

   // way 02 
   if ( (n & ( n - 1 )) == 0 ){
       cout << "The input is power of 2" << '\n';
   }
   else{
       cout << "The input is not power of 2" << '\n';
   }

    return 0;
}