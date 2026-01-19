#include <bits/stdc++.h>
using namespace std;

struct State {
    deque<int> dq1, dq2;
    bool operator<(State const &other) const {
        if (dq1 != other.dq1) {
            return dq1 < other.dq1;
        }
        return dq2 < other.dq2;
    }
};

void solve() {
    int n, k1, k2;
    set<State> st;
    deque<int> dq1, dq2;
    cin >> n;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int x;
        cin >> x;
        dq1.push_back(x);
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int x;
        cin >> x;
        dq2.push_back(x);
    }
    int step = 0;
    while (!dq1.empty() && !dq2.empty()) {
        State now;
        now.dq1 = dq1, now.dq2 = dq2;
        if (st.contains(now)) {
            break;
        }
        st.insert(now);
        int top1 = dq1.front(), top2 = dq2.front();
        dq1.pop_front(), dq2.pop_front();
        if (top1 > top2) {
            dq1.push_back(top2), dq1.push_back(top1);
        } else {
            dq2.push_back(top1), dq2.push_back(top2);
        }
        step++;
    }
    if (dq1.empty()) {
        cout << step << " 2\n";
    } else if (dq2.empty()) {
        cout << step << " 1\n";
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
