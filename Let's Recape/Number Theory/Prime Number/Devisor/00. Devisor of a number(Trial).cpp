//Number of devisor ( TC -->  sqrt(n) )
#include <bits/stdc++.h>
using namespace std ;

vector<int> v; 
void devisor(int n){
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            int x = i;
            int y = n / i;
            v.push_back(x);
            if (x != y) v.push_back(y);
        }
    }
}
int main()
{
    int n ;
    cin>> n ;
    devisor ( n );

    sort(v.begin(),v.end());
    cout << "Number of devisors : " << v.size() << '\n';
    int sum = 0 ;
    for ( auto it : v ){
        sum = sum + it ;
    }
    cout << "Sum of devisors : " << sum << '\n';

    return 0 ;
}

