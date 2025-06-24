#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    for (int i = 0; i < (1 << 8); i++) {
        vector<int> temp(n);
        int val = 0;
        for (int j = 0; j < n; j++) {
            temp[j] = a[j] ^ i;
            val = val ^ temp[j];
        }
        if (!val) {
            cout << i << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
