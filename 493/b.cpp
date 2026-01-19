#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> p1, p2;
    int64_t last = 0;
    for (int i = 0; i < n; i++) {
        int64_t x;
        cin >> x;
        if (x > 0) {
            p1.push_back(x);
        } else {
            p2.push_back(-x);
        }
        last = x;
    }
    int64_t po1 = accumulate(p1.begin(), p1.end(), 0LL),
            po2 = accumulate(p2.begin(), p2.end(), 0LL);
    if (po1 > po2) {
        cout << "first\n";
        return;
    } else if (po1 < po2) {
        cout << "second\n";
        return;
    }
    if (p1 != p2) {
        int sz1 = (int)p1.size(), sz2 = (int)p2.size();
        for (int i = 0; i < min(sz1, sz2); i++) {
            if (p1[i] < p2[i]) {
                cout << "second\n";
                return;
            } else if (p1[i] > p2[i]) {
                cout << "first\n";
                return;
            }
        }
        if (sz1 > sz2) {
            cout << "first\n";
            return;
        } else if (sz1 < sz2) {
            cout << "second\n";
            return;
        }
    }
    if (last < 0) {
        cout << "second\n";
    } else {
        cout << "first\n";
    }
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
