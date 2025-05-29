https://leetcode.com/problems/ugly-number-ii/
// Leetcode Formate :
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n + 1);
        ans[1] = 1;
        generateUgly(2, 1, 1, 1, n, ans);
        return ans[n];
    }

private:
    void generateUgly(int pos, int t2, int t3, int t5, int n, vector<int>& ans) {
        if (pos > n) return;

        int val2 = ans[t2] * 2;
        int val3 = ans[t3] * 3;
        int val5 = ans[t5] * 5;

        int mn = min({val2, val3, val5});
        ans[pos] = mn;

        if (mn == val2) t2++;
        if (mn == val3) t3++;
        if (mn == val5) t5++;

        generateUgly(pos + 1, t2, t3, t5, n, ans);
    }
};


// CF formate :

// Iterative Dp ( Prefarable for this kind of problem )
#include<bits/stdc++.h>
using namespace std ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n ; cin >> n ;
    vector<int > ans(n+1);
    ans[1] = 1 ;

    int t2 , t3 , t5;
    t2 = t3 = t5 = 1 ;
    for ( int i = 2 ; i <= n ; i++ ){
        int val2 = ans[t2]*2;
        int val3 = ans[t3]*3;
        int val5 = ans[t5]*5;

        int mn = min( val2 , min( val3 , val5));
        ans[i] = mn ;
        if ( mn == val2 ){
            t2++;
        }
        if ( mn == val3 ){
            t3++;
        }
        if( mn == val5 ){
            t5++;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ){
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0 ;
}


// Recursive Dp 
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

void yo(int pos, int t2, int t3, int t5) {
    if (pos > n) return;

    int val2 = ans[t2] * 2;
    int val3 = ans[t3] * 3;
    int val5 = ans[t5] * 5;

    int mn = min({val2, val3, val5});
    ans[pos] = mn;

    if (mn == val2) t2++;
    if (mn == val3) t3++;
    if (mn == val5) t5++;

    yo(pos + 1, t2, t3, t5);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    ans.resize(n + 1);

    ans[1] = 1;
    yo(2, 1, 1, 1); 

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}
