#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> wall(2, vector<char>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++)
            cin >> wall[i][j];
    }
    vector<vector<bool>> dp(2, vector<bool>(n, false));
    dp[0][0] = (wall[0][0] == 'B');
    dp[1][0] = (wall[1][0] == 'B');
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < 2; i++) {
            dp[i][j] = (dp[i ^ 1][j] || dp[i][j - 1]) && (wall[i][j] == 'B');
        }
        for (int i = 1; i >= 0; i--) {
            dp[i][j] = (dp[i ^ 1][j] || dp[i][j - 1]) && (wall[i][j] == 'B');
        }
    }
    auto ok = [&]() -> bool {
        // case where forced to touch a black cell twice
        vector<int> check;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            cnt += (wall[0][i] == 'B') + (wall[1][i] == 'B');
            if (cnt == 1) {
                check.push_back(i);
            }
        }
        for (int i = 0; i < (int)check.size() - 1; i++) {
            auto now = check[i], nxt = check[i + 1];
            int l = (wall[0][now] != 'B' ? 0 : 1);
            int r = (wall[0][nxt] != 'B' ? 0 : 1);
            int dist = nxt - now;
            if (dist > 1) {
                // there exist BB
                if (((l ^ r) && (dist & 1)) ||
                    ((l ^ r) == 0) && (dist % 2 == 0)) {
                    return false;
                }
            }
        }
        return true;
    };
    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cerr << dp[i][j];
    //     }
    //     cerr << '\n';
    // }
    if ((dp[0][n - 1] || dp[1][n - 1]) && ok()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
