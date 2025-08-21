#include <bits/stdc++.h>
using namespace std;

// First implementation ( judge solution )
int solve1(int n, string s) {
    int one = count(s.begin(), s.end(), '1');
    if (one & 1) return -1;
    bool adj = 0;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == '1' and s[i] == s[i + 1]) adj = 1;
    if (one != 2 or !adj) return one / 2;
    if (n == 3) return -1;
    if (n == 4 and s == "0110") return 3;
    return 2;
}

// Second implementation ( my solution )
int solve2(int n, string s) {
    int cnt = count(s.begin(), s.end(), '1');
    int x = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '1' && s[i - 1] == s[i]) {
            x++;
        }
    }

    if (cnt % 2) {
        return -1;
    } else {
        if (x == 1) {
            if (s == "110" or s == "011") {
                return -1;
            } else if (s == "0110") {
                return 3;
            } else {
                return 2;
            }
        } else {
            return cnt / 2;
        }
    }
}

int main() {
    srand(time(0));
    int T = 100000;
    for (int t = 1; t <= T; t++) {
        int n = rand() % 10 + 2; 
        string s = "";
        for (int i = 0; i < n; i++) {
            s += (rand() % 2) + '0';
        }

        int res1 = solve1(n, s);
        int res2 = solve2(n, s);

        if (res1 != res2) {
            cout << "Mismatch found!\n";
            cout << "Test #" << t << "\n";
            cout << "n = " << n << "\n";
            cout << "s = " << s << "\n";
            cout << "solve1: " << res1 << "\n";
            cout << "solve2: " << res2 << "\n";
            return 0;
        }
    }

    cout << "All test cases matched!\n";
    return 0;
}

// Problem : https://atcoder.jp/contests/arc156/tasks/arc156_a