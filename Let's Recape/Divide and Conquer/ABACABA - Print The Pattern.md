``` cpp
// problem : https://www.spoj.com/problems/ABACABA/

Code : 
#include <bits/stdc++.h>
using namespace std;

string yo(int n) {
    if (n == 1) return "A";
    char mid = char(64 + n);  // 64 + n = ASCII for 'A' + (n - 1)
    string left = yo(n - 1);
    return left + mid + left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    cout << yo(n);  
    
    return 0;
}
```