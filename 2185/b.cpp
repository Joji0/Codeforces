#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N;
        cin >> N;
        vector<int> A(N);
        for (auto &x : A) cin >> x;
        int mx = *max_element(A.begin(), A.end());
        cout << mx * N << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        cin >> t;
        while (t--) solve();

        return 0;
}
