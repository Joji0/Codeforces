#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N, M;
        int64_t H;
        cin >> N >> M >> H;
        vector<int64_t> original(N), A(N);
        for (auto &x : original) cin >> x;
        A = original;
        vector<int> last_touched(N, 0);
        int last_reset = -1;
        for (int i = 1; i <= M; i++) {
                int idx;
                int64_t add;
                cin >> idx >> add;
                idx--;
                int64_t new_val;
                if (last_touched[idx] < last_reset) {
                        new_val = original[idx] + add;
                } else {
                        new_val = A[idx] + add;
                }
                last_touched[idx] = i;
                if (new_val > H) {
                        last_reset = i;
                        A[idx] = original[idx];
                } else {
                        A[idx] = new_val;
                }
        }
        for (int i = 0; i < N; i++) {
                if (last_touched[i] < last_reset) {
                        cout << original[i] << " ";
                } else {
                        cout << A[i] << " ";
                }
        }
        cout << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        cin >> t;
        while (t--) solve();

        return 0;
}
