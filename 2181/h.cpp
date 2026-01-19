#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t W, H, D, N;
    cin >> W >> H >> D >> N;
    auto f = [](const int64_t &x) -> vector<int64_t> {
        vector<int64_t> ret;
        for (int64_t i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                ret.push_back(i);
                if (x % (x / i) == 0 && i != x / i) {
                    ret.push_back(x / i);
                }
            }
        }
        return ret;
    };
    vector<int64_t> fw = f(W), fh = f(H), fd = f(D);
    set<int64_t> sd(fd.begin(), fd.end());
    for (auto &x : fw) {
        if (N % x == 0) {
            for (auto &y : fh) {
                if ((N / x) % y == 0) {
                    int64_t need = (N / (x * y));
                    if (sd.contains(need) && x * y * need == N) {
                        cout << x - 1 << " " << y - 1 << " " << need - 1
                             << '\n';
                        return;
                    }
                }
            }
        }
    }
    cout << "-1\n";
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
