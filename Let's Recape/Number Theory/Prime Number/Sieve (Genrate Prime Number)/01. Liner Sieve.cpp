// Code ( Linear scieve ) ( TC -->  O(n) )
#include<bits/stdc++.h>
using namespace std ;

const int mx = 1e7+123;
vector<int> v (mx + 1);
vector<int> prime ;

int main()
{
    for (int i = 2; i <= mx; i++ ){
        if (v[i] == 0){
            v[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= mx; j++){
            v[i * prime[j]] = prime[j];
            if (prime[j] == v[i]){
                break;
            }
        }
    }

    for ( auto it : prime ){
        cout << it << " ";
    }
    cout << '\n';

    return 0 ;
}

//Code ( Tc -> almost O(n))
#include<bits/stdc++.h>
using namespace std ;

const int mx = 1e7+9 ;
bitset <mx> prime ;
vector< int > ans ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for ( int i = 1 ; i < mx ; i++ ){
        prime[i] = true ;
    }

    for ( int  i = 4 ; i < mx ; i+=2 ){
        prime[i] = false ;
    }

    for( int i = 3 ; i < mx ; i+=2 ){
        if ( prime[i]){
          for( int j = 2*i ; j < mx ; j += i){
              prime[j] = false ;
          }
        }
    }

    for ( int i = 2 ; i < mx ; i++ ){
        if ( prime[i]){
            ans.push_back(i);
        }
    }

    for ( auto it : ans ){
        cout << it << " ";
    }
    cout << '\n';

    return 0 ;
}