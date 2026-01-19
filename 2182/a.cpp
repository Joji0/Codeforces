#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    string s;
    cin >> N >> s;
    const string s1 = "2026", s2 = "2025";
    int ans = 25;
    for (int i = 0; i < N - 3; i++) {
        int now = 0;
        for (int j = i; j <= i + 3; j++) {
            if (s[j] != s1[j - i]) {
                now++;
            }
        }
        ans = min(ans, now);
    }
    int ok = 0;
    for (int i = 0; i < N - 3; i++) {
        bool now = true;
        for (int j = i; j <= i + 3; j++) {
            if (s[j] != s2[j - i]) {
                now = false;
                break;
            }
        }
        if (now) {
            ok = 1;
        }
    }
    cout << min(ans, ok) << '\n';
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
