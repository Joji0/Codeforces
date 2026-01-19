#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int64_t k;
    cin >> n >> k;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    int sz = A.size();
    unordered_set<int64_t> st(A.begin(), A.end());
    unordered_map<int64_t, int> idx;
    for (int i = 0; i < sz; i++)
        idx[A[i]] = i;
    vector<bool> covered(sz, false);
    vector<int64_t> ans;
    for (int i = 0; i < sz; i++) {
        if (covered[i])
            continue;
        int64_t need = k / A[i];
        if (need > sz) {
            cout << "-1\n";
            return;
        }
        bool valid = true;
        for (int64_t m = A[i]; m <= k; m += A[i]) {
            if (!st.count(m)) {
                valid = false;
                break;
            }
            covered[idx[m]] = true;
        }
        if (!valid) {
            cout << "-1\n";
            return;
        }
        ans.push_back(A[i]);
    }
    cout << ans.size() << '\n';
    for (auto &b : ans)
        cout << b << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
