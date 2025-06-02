#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int minim = 1e9, idx = 0;
    for (int i = 1; i < n; i++) {
        int diff = abs(h[i] - h[i - 1]);
        if (diff < minim) {
            minim = diff;
            idx = i;
        }
    }
    if (abs(h[n - 1] - h[0]) < minim) {
        cout << n << " " << 1 << '\n';
        return;
    }
    cout << idx << " " << idx + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
