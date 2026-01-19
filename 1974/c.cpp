#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A)
        cin >> x;
    map<array<int, 3>, int> mp;
    map<array<int, 2>, int> mp1, mp2, mp3;
    int64_t ans = 0;
    for (int i = 0; i < n - 2; i++) {
        mp[{A[i], A[i + 1], A[i + 2]}]++;
        mp1[{A[i], A[i + 1]}]++;
        mp2[{A[i], A[i + 2]}]++;
        mp3[{A[i + 1], A[i + 2]}]++;
    }
    // for (auto &[arr, cnt] : mp) {
    //     auto [a, b, c] = arr;
    //     if (mp1.contains({a, b})) {
    //         ans += cnt * (mp1[{a, b}] - cnt);
    //         mp1.erase({a, b});
    //     }
    //     if (mp2.contains({a, c})) {
    //         ans += cnt * (mp2[{a, c}] - cnt);
    //         mp2.erase({a, c});
    //     }
    //     if (mp3.contains({b, c})) {
    //         ans += cnt * (mp3[{b, c}] - cnt);
    //         mp3.erase({b, c});
    //     }
    // }
    for (auto &[p, cnt] : mp1) {
        ans += 1LL * cnt * (cnt - 1) / 2;
    }
    for (auto &[p, cnt] : mp2) {
        ans += 1LL * cnt * (cnt - 1) / 2;
    }
    for (auto &[p, cnt] : mp3) {
        ans += 1LL * cnt * (cnt - 1) / 2;
    }
    for (auto &[arr, cnt] : mp) {
        ans -= 3LL * cnt * (cnt - 1) / 2;
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
