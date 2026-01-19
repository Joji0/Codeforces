#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
    auto ok = [&](const vector<int> &v) -> bool {
        int f = -1, l = -1;
        for (int i = 0; i < N; i++) {
            if (v[i] == 1) {
                f = i;
                break;
            }
        }
        for (int i = N - 1; i >= 0; i--) {
            if (v[i] == 1) {
                l = i;
                break;
            }
        }
        assert(f != -1 && l != -1);
        for (int i = f; i <= l; i++) {
            if (!v[i])
                return false;
        }
        return true;
    };
    int ans = 0;
    while (!ok(A)) {
        for (int i = N - 1; i >= 0; i--) {
            if (A[i]) {
                for (int j = i - 1; j >= 0; j--) {
                    if (A[j] == 0) {
                        A[j] = 1;
                        break;
                    }
                }
                A[i] = 0;
                ans++;
                break;
            }
        }
    }
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
