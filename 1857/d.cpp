#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), ans;
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<tuple<int, int, int>> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = {a[i], b[i], i + 1};
    }
    sort(c.begin(), c.end(),
         [](tuple<int, int, int> p1, tuple<int, int, int> p2) {
             return get<0>(p1) - get<1>(p1) > get<0>(p2) - get<1>(p2);
         });
    int val = get<0>(c.front()) - get<1>(c.front());
    for (int i = 0; i < n; i++) {
        if (get<0>(c[i]) - get<1>(c[i]) == val) {
            ans.push_back(get<2>(c[i]));
        } else {
            break;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
