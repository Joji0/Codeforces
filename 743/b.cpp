#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N;
        int64_t K;
        cin >> N >> K;
        cout << __builtin_ctzll(K) + 1 << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
