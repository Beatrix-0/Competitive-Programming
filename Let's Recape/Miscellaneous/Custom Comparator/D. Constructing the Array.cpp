#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<int,pair<int,int>>& a,
                    const pair<int,pair<int,int>>& b) const {
        if (a.first == b.first)
            return a.second.first > b.second.first; // smaller l first
        return a.first < b.first; // larger size first
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> pq;
        pq.push({n, {1, n}});

        vector<int> ans(n+1);
        int step = 1;

        while (!pq.empty()) {
            auto [sz, range] = pq.top();
            auto [l, r] = range;
            pq.pop();

            int mid;
            if (sz % 2) mid = (l + r) / 2;
            else mid = (l + r - 1) / 2;

            ans[mid] = step++;

            int nszl = mid - l;
            int nszr = r - mid;

            if (nszl > 0) pq.push({nszl, {l, mid - 1}});
            if (nszr > 0) pq.push({nszr, {mid + 1, r}});
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}

// https://codeforces.com/problemset/problem/1353/D