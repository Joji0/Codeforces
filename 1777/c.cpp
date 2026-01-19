#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
    map<int, int> check, memo;
    int covered = 0;
    sort(A.begin(), A.end());
    auto add = [&](int idx, map<int, int> &m, bool ok = true) {
        auto x = A[idx];
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                if (i <= M) {
                    m[i]++;
                    if (ok && m[i] == 1) {
                        covered++;
                    }
                }
                if (x % (x / i) == 0 && i != x / i && x / i <= M) {
                    m[x / i]++;
                    if (ok && m[x / i] == 1) {
                        covered++;
                    }
                }
            }
        }
    };
    auto rem = [&](int idx, map<int, int> &m) {
        auto x = A[idx];
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                if (i <= M) {
                    m[i]--;
                    if (!m[i]) {
                        m.erase(i);
                        covered--;
                    }
                }
                if (x % (x / i) == 0 && i != x / i && x / i <= M) {
                    m[x / i]--;
                    if (!m[x / i]) {
                        m.erase(x / i);
                        covered--;
                    }
                }
            }
        }
    };
    for (int i = 0; i < N; i++) {
        add(i, check, false);
    }
    if ((int)check.size() != M) {
        cout << "-1\n";
        return;
    }
    int l = 0, ans = INF;
    for (int r = 0; r < N; r++) {
        add(r, memo);
        while (l < r && covered == M) {
            ans = min(ans, A[r] - A[l]);
            rem(l, memo);
            l++;
        }
        if (covered == M) {
            ans = min(ans, A[r] - A[l]);
        }
    }
    assert(ans != INF);
    cout << ans << '\n';
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
