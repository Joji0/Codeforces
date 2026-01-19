#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string ans;
    int diff = 0;
    for (int i = 0; i < N; i++) {
        int a, g;
        cin >> a >> g;
        if (diff - g < -500) {
            ans.push_back('A');
            diff += a;
        } else {
            ans.push_back('G');
            diff -= g;
        }
    }
    if (diff <= 500) {
        cout << ans << '\n';
    } else {
        cout << "-1\n";
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
