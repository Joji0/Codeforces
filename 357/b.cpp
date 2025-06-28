#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    set<int> done;
    vector<int> colors(n + 1, 0);
    while (m--) {
        int a, b, c, al = -1;
        cin >> a >> b >> c;
        for (auto x : {a, b, c}) {
            if (done.find(x) != done.end()) {
                al = x;
                break;
            }
        }
        if (al == -1) {
            colors[a] = 1, colors[b] = 2, colors[c] = 3;
        } else {
            int badcolor = colors[al], start = (badcolor == 1 ? 2 : 1);
            for (auto x : {a, b, c}) {
                if (x == al)
                    continue;
                colors[x] = start++;
                if (start == badcolor)
                    start++;
            }
        }
        done.insert(a), done.insert(b), done.insert(c);
    }
    for (int i = 1; i <= n; i++) {
        cout << colors[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
