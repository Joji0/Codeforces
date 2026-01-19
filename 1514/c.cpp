#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N;
        cin >> N;
        vector<int> seq;
        for (int i = 1; i < N; i++) {
                if (gcd(i, N) == 1) {
                        seq.push_back(i);
                }
        }
        int64_t prod = 1;
        for (auto &x : seq) {
                prod *= x;
                prod %= N;
        }
        if (prod == 1) {
                cout << (int)seq.size() << '\n';
                for (auto &x : seq) {
                        cout << x << " ";
                }
                cout << '\n';
        } else {
                cout << (int)seq.size() - 1 << '\n';
                for (auto &x : seq) {
                        if (x == prod) continue;
                        cout << x << " ";
                }
                cout << '\n';
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
