#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q, best = 0;
    cin >> n >> q;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        dq.push_back(k);
        best = max(best, k);
    }
    int bound = 0;
    vector<array<int, 2>> below;
    while (dq.front() != best) {
        bound++;
        int f = dq[0], b = dq[1];
        below.push_back({f, b});
        dq.pop_front();
        dq.pop_front();
        if (f < b) {
            swap(f, b);
        }
        dq.push_front(f);
        dq.push_back(b);
    }
    while (q--) {
        int64_t ask;
        cin >> ask;
        if (ask <= bound) {
            ask--;
            cout << below[ask][0] << " " << below[ask][1] << '\n';
        } else {
            cout << best << " " << dq[1 + (ask - (bound + 1)) % (n - 1)]
                 << '\n';
        }
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

/*
 * 1: 1 2 3 4 5
 * 2: 2 3 4 5 1
 * 3: 3 4 5 1 2
 * 4: 4 5 1 2 3
 * 5: 5 1 2 3 4
 * 6: 5 2 3 4 1
 * 7: 5 3 4 1 2
 * 8: 5 4 1 2 3
 * 9: 5 1 2 3 4
 * observation: wait until the greatest element comes in front and its just
 * rotation after that
 */
