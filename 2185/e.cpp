#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> A(N), B(M);
        for (auto &x : A) cin >> x;
        for (auto &x : B) cin >> x;
        sort(B.begin(), B.end());
        string s;
        cin >> s;
        vector<array<int, 2>> go_left, go_right;
        int curr = 0;
        for (int i = 0; i < K; i++) {
                if (s[i] == 'L') {
                        curr--;
                } else {
                        curr++;
                }
                if (curr <= 0) {
                        go_left.push_back({-curr, i});
                } else {
                        go_right.push_back({curr, i});
                }
        }
        sort(go_left.begin(), go_left.end(), [](const auto &a, const auto &b) {
                if (a[0] != b[0])
                        return a[0] < b[0];
                else
                        return a[1] < b[1];
        });
        sort(go_right.begin(), go_right.end(), [](const auto &a, const auto &b) {
                if (a[0] != b[0])
                        return a[0] < b[0];
                else
                        return a[1] < b[1];
        });
        vector<int> die(K, 0);
        int lsiz = (int)go_left.size(), rsiz = (int)go_right.size();
        for (int i = 0; i < N; i++) {
                auto it1 = upper_bound(B.begin(), B.end(), A[i]), it2 = lower_bound(B.begin(), B.end(), A[i]);
                int64_t time_left = INF, time_right = INF;
                if (it1 != B.begin()) {
                        it1--;
                        int64_t search = abs(A[i] - *it1);
                        int64_t l = 0, r = lsiz - 1, ans = INF;
                        while (l <= r) {
                                int mid = (l + r) / 2;
                                if (go_left[mid][0] >= search) {
                                        ans = min(ans, (int64_t)go_left[mid][1]);
                                        r = mid - 1;
                                } else {
                                        l = mid + 1;
                                }
                        }
                        time_left = min(time_left, ans);
                }
                if (it2 != B.end()) {
                        int64_t search = abs(A[i] - *it2);
                        int64_t l = 0, r = rsiz - 1, ans = INF;
                        while (l <= r) {
                                int mid = (l + r) / 2;
                                if (go_right[mid][0] >= search) {
                                        ans = min(ans, (int64_t)go_right[mid][1]);
                                        r = mid - 1;
                                } else {
                                        l = mid + 1;
                                }
                        }
                        time_right = min(time_right, ans);
                }
                int64_t time = min(time_left, time_right);
                if (time >= 0 && time < K) die[time]++;
        }
        int64_t alive = N;
        for (int i = 0; i < K; i++) {
                alive -= die[i];
                cout << alive << " \n"[i == K - 1];
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        cin >> t;
        while (t--) solve();

        return 0;
}
