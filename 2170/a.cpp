#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    int h = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = h;
            h++;
        }
    }
    int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cerr << g[i][j] << " ";
    //     }
    //     cerr << '\n';
    // }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int now = g[i][j];
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    now += g[nx][ny];
                }
            }
            ans = max(ans, now);
        }
    }
    cout << ans << '\n';
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
