#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    sort(A.begin(), A.end());
    map<int64_t, int> mp;
    for (auto &x : A) {
        mp[x]++;
    }
    int64_t f = -1, s = -1, cntf = 0;
    for (auto &[el, cnt] : mp) {
        if (cnt * N >= K) {
            f = el;
            cntf = cnt;
            break;
        } else {
            K -= cnt * N;
        }
    }
    for (auto &[el, cnt] : mp) {
        if (cntf * cnt >= K) {
            s = el;
            break;
        } else {
            K -= cntf * cnt;
        }
    }
    cout << f << " " << s << '\n';
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
