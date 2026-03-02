#include <bits/stdc++.h>
using namespace std;

const int BAD = -1e9;

void solve() {
        int N;
        cin >> N;
        vector<int> D(N);
        for (auto &x : D) cin >> x;
        vector<vector<char>> grid(N, vector<char>(3));
        vector<vector<bool>> valid(N, vector<bool>(3, false));
        for (int i = 0; i < N; i++) {
                string s = to_string(D[i]);
                for (int j = 2; j >= 3 - (int)s.size(); j--) {
                        valid[i][j] = true;
                }
                while (s.size() < 3) {
                        s = "0" + s;
                }
                for (int j = 0; j < 3; j++) {
                        grid[i][j] = s[j];
                }
        }
        vector<int> used(N, 0);
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < 3; j++) {
                        cerr << grid[i][j];
                }
                cerr << '\n';
        }
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < 3; j++) {
                        cerr << valid[i][j];
                }
                cerr << '\n';
        }
        for (int j = 0; j < 3; j++) {

                for (int i = 0; i < N; i++) {
                        if (!use_once && grid[i][j] != '0' && used[i] != BAD) {
                                if (!used[i]) {
                                        use_once = true;
                                        used[i] = true;
                                }
                        } else if (grid[i][j] == '0' && valid[i][j] && used[i] != BAD) {
                                used[i] = true;
                        } else {
                                used[i] = BAD;
                        }
                }
        }
        vector<int> ans;
        for (int i = 0; i < N; i++) {
                if (used[i]) {
                        ans.push_back(D[i]);
                }
        }
        cout << (int)ans.size() << '\n';
        for (auto &x : ans) {
                cout << x << " ";
        }
        cout << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
