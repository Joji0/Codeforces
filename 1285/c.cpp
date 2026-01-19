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

int64_t binexp(int64_t a, int64_t b) {
    int64_t res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

void solve() {
    int64_t x;
    cin >> x;
    if (x == 1) {
        cout << "1 1\n";
        return;
    }
    vector<array<int64_t, 2>> divs = trial_division1(x);
    divs.push_back({1, 1});
    vector<int64_t> check;
    for (auto &x : divs) {
        check.push_back(binexp(x[0], x[1]));
    }
    int n = (int)check.size();
    int64_t l = -1, r = -1;
    for (int mask = 0; mask < (1 << n); mask++) {
        int64_t start = 1;
        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) {
                start *= check[i];
            }
        }
        int64_t left = x / start;
        if ((l == -1 && r == -1) || max(start, left) < max(l, r)) {
            l = start, r = left;
        }
    }
    assert(l != -1 && r != -1 && lcm(l, r) == x);
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
