#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    int myX = 0, myY = 0, bonus = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '4') {
            myX++;
            myY++;
        } else {
            bonus++;
            myX++;
            myY++;
        }
    }
    if (x < -myX || x > myX || y < -myY || y > myY) {
        cout << "NO\n";
    } else {
        if (abs(x) + abs(y) <= myX + bonus) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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
