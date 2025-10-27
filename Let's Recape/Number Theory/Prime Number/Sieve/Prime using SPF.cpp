#include<bits/stdc++.h>
using namespace std ;

const int mx =100000000 ;
int spf[mx + 1];
vector<int> primes;

void SPF() {
    for (int i = 2; i <= mx; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || i * p > mx) break;
            spf[i * p] = p;
        }
    }

    for ( int i = 0 ; i < primes.size() ; i++ ){
            if ( (i+1) % 100 == 1 ){
            cout << primes[i]<< '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    SPF();
    return 0 ;
}

// Problem : https://www.spoj.com/problems/TDPRIMES/
