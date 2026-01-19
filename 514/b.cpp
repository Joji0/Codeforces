#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    auto f = [&](const int &a, const int &b) -> array<int, 2> {
        int atas = y - b, bawah = x - a;
        int g = gcd(atas, bawah);
        atas /= g, bawah /= g;
        return {atas, bawah};
    };
    map<array<int, 2>, int> mp;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        auto F = f(u, v);
        if (mp.contains({-F[0], -F[1]})) {
            mp[{-F[0], -F[1]}]++;
        } else {
            mp[{F[0], F[1]}]++;
        }
    }
    cout << (int)mp.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
};
