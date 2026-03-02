#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
                cout << i << " \n"[i == N];
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
