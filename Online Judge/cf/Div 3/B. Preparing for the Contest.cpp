#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   int t ;
   cin >> t ;
   while ( t-- )
   {
      int x , k ;
      cin >> x >> k ;
 
      if ( k == 0 )
      {
          for ( int i = x ; i > 0 ; i--)
          {
              cout << i << " ";
          }
          cout << '\n';
      }
      else
      {
          for ( int i = 1 ; i <= k ; i++ )
          {
              cout << i << " ";
          }
          for ( int i = x ; i > k ; i--)
          {
              cout << i << " ";
          }
          cout << '\n';
      }
   }
 
    return 0;
}

