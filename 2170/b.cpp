#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> B(n);
    for (auto &x : B)
        cin >> x;
    if (*max_element(B.begin(), B.end()) == 1) {
        cout << "1\n";
    } else {
        int ans = n;
        for (auto &x : B)
            if (!x)
                ans--;
        cout << ans << '\n';
    }
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
