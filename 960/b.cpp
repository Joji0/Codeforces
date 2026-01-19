#include <bits/stdc++.h>
using namespace std;

struct CMP {
    bool operator()(const int64_t &A, const int64_t &B) {
        return abs(A) < abs(B);
    }
};

void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    priority_queue<int64_t, vector<int64_t>, CMP> pq;
    vector<int64_t> A(n), B(n);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    for (int i = 0; i < n; i++) {
        pq.push(abs(A[i] - B[i]));
    }
    for (int i = 0; i < k1 + k2; i++) {
        int64_t f = pq.top();
        pq.pop();
        pq.push(abs(f - 1));
    }
    int64_t ans = 0;
    while (!pq.empty()) {
        ans += pq.top() * pq.top();
        pq.pop();
    }
    cout << ans << '\n';
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
