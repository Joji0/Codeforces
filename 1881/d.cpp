#include <bits/stdc++.h>
using namespace std;

vector<array<int64_t, 2>> trial_division1(int64_t n) {
    vector<array<int64_t, 2>> factorization;
    for (long long d = 2; d * d <= n; d++) {
        int cnt = 0;
        if (n % d == 0) {
            while (n % d == 0) {
                cnt++;
                n /= d;
            }
            factorization.push_back({d, cnt});
        }
    }
    if (n > 1)
        factorization.push_back({n, 1});
    return factorization;
}

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n);
    map<int64_t, int> mp;
    for (auto &x : A) {
        cin >> x;
        auto g = trial_division1(x);
        for (auto &[el, cnt] : g) {
            mp[el] += cnt;
        }
    }
    for (auto &[el, cnt] : mp) {
        if (el == 1)
            continue;
        if (cnt % n) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
