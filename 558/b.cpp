#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    map<int, vector<int>> mp;
    int mx = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]].push_back(i + 1);
        mx = max(mx, (int)mp[A[i]].size());
    }
    int l = 1, r = N;
    for (auto &[_, V] : mp) {
        if ((int)V.size() == mx) {
            int now = V.back() - V.front() + 1;
            if (now < r - l + 1) {
                l = V.front(), r = V.back();
            }
        }
    }
    cout << l << " " << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
