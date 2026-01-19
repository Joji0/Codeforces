#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int curr = 1, shift = 1;
    for (int i = 0; i < n - 1; i++) {
        curr += shift;
        if (curr % n != 0)
            curr %= n;
        shift++;
        cout << curr << " ";
        curr %= n;
    }
    cout << '\n';
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
