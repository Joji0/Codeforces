#include <bits/stdc++.h>
using namespace std;

void solve() {
    int sum, lim;
    cin >> sum >> lim;
    int cnt = 0;
    for (int i = 1; i <= lim; i++) {
        cnt += (i) & (-i);
    }
    if (sum > cnt) {
        cout << "-1\n";
        return;
    }
    vector<bool> use(lim + 1, false);
    vector<array<int, 2>> opt;
    for (int i = 1; i <= lim; i++) {
        opt.push_back({i, (i) & (-i)});
    }
    sort(opt.begin(), opt.end(),
         [](const auto &a, const auto &b) { return a[1] < b[1]; });
    int i = (int)opt.size() - 1;
    while (sum > 0 && i >= 0) {
        if (sum - opt[i][1] >= 0) {
            use[opt[i][0]] = true;
            sum -= opt[i][1];
        }
        i--;
    }
    vector<int> ans;
    for (int i = 0; i <= lim; i++) {
        if (use[i])
            ans.push_back(i);
    }
    cout << (int)ans.size() << '\n';
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << '\n';
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
