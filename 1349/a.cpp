#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

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
    int n;
    cin >> n;
    vector<int64_t> A(n);
    // min, sec min
    map<int64_t, array<int64_t, 2>> mp;
    map<int, int> cnt;
    for (auto &x : A) {
        cin >> x;
        auto g = trial_division1(x);
        for (auto &[f, mul] : g) {
            if (!mp.contains(f)) {
                mp[f] = {mul, INF};
            } else {
                auto arr = mp[f];
                if (mul <= arr[0]) {
                    mp[f][1] = mp[f][0];
                    mp[f][0] = mul;
                } else if (mul < arr[1]) {
                    mp[f][1] = mul;
                }
            }
            cnt[f]++;
        }
    }
    int64_t ans = 1;
    for (auto &[val, count] : cnt) {
        if (count == n) {
            ans *= binexp(val, mp[val][1]);
        } else if (count == n - 1) {
            ans *= binexp(val, mp[val][0]);
        }
    }
    cout << ans << '\n';
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
