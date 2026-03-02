#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N;
        string a, b;
        cin >> N >> a >> b;
        string ans;
        for (int i = 0; i < N; i++) {
                if (a[i] == b[i]) {
                        if (a[i] == 'P') {
                                ans.push_back('S');
                        } else if (a[i] == 'R') {
                                ans.push_back('P');
                        } else {
                                ans.push_back('R');
                        }
                } else {
                        // P R S
                        if (a[i] > b[i]) swap(a[i], b[i]);
                        if (a[i] == 'P' && b[i] == 'R') {
                                ans.push_back('P');
                        } else if (a[i] == 'P' && b[i] == 'S') {
                                ans.push_back('S');
                        } else if (a[i] == 'R' && b[i] == 'S') {
                                ans.push_back('R');
                        } else {
                                assert(false);
                        }
                }
        }
        cout << ans << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
