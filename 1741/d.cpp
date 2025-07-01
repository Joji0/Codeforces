#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int ans = 0;

void DC(vector<int> &a, vector<int> &b) {
    if (a.empty())
        return;
    if (*max_element(a.begin(), a.end()) > *min_element(b.begin(), b.end()) ||
        *min_element(a.begin(), a.end()) > *max_element(b.begin(), b.end())) {
        ans++;
        swap(a, b);
    }
    int mida = a.size() / 2, midb = b.size() / 2;
    vector<int> la(a.begin(), a.begin() + mida), ra(a.begin() + mida, a.end()),
        lb(b.begin(), b.begin() + midb), rb(b.begin() + midb, b.end());
    DC(la, ra), DC(lb, rb);
    vector<int> ma = la, mb = lb;
    for (auto &x : ra) {
        ma.push_back(x);
    }
    for (auto &x : rb) {
        mb.push_back(x);
    }
    a = ma, b = mb;
}

void solve() {
    ans = 0;
    int m;
    cin >> m;
    vector<int> a(m / 2), b(m / 2);
    if (m == 1) {
        int trash;
        cin >> trash;
        cout << "0\n";
        return;
    }
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    DC(a, b);
    vector<int> f(m);
    for (int i = 0; i < m / 2; i++) {
        f[i] = a[i];
    }
    for (int i = m / 2; i < m; i++) {
        f[i] = b[i - m / 2];
    }
    if (!is_sorted(f.begin(), f.end())) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
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
