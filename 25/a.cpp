#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    bool search_even = true;
    if ((v[0] % 2 == 0 && v[1] % 2 == 0) ||
        (v[0] % 2 == 0 && v[1] % 2 && v[2] % 2 == 0) ||
        (v[0] % 2 && v[1] % 2 == 0 && v[2] % 2 == 0)) {
        search_even = false;
    }
    for (int i = 0; i < n; i++) {
        if (search_even) {
            if (v[i] % 2 == 0) {
                cout << i + 1 << '\n';
                break;
            }
        } else {
            if (v[i] % 2) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
