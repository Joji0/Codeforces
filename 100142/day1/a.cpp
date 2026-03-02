#include <bits/stdc++.h>
using namespace std;

void solve() {
        int64_t X;
        cin >> X;
        int64_t root = (int64_t)sqrt(X);
        if (root * root == X) {
                cout << "1\n";
        } else {
                cout << "0\n";
        }
}

int main() {
        freopen("veryhard.in", "r", stdin);
        freopen("veryhard.out", "w", stdout);

        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        cin >> t;
        while (t--) solve();

        return 0;
}
