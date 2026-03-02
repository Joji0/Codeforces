#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N, S, X;
        cin >> N >> S >> X;
        vector<int> A(N);
        for (auto &x : A) cin >> x;
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum > S) {
                cout << "NO\n";
        } else {
                cout << ((S - sum) % X == 0 ? "YES\n" : "NO\n");
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        cin >> t;
        while (t--) solve();

        return 0;
}
