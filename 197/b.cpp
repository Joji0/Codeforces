#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N + 1), Q(M + 1);
    for (auto &x : P)
        cin >> x;
    for (auto &x : Q)
        cin >> x;
    if (N < M) {
        cout << "0/1\n";
    } else if (N > M) {
        bool sign = (P[0] * Q[0] < 0);
        if (sign) {
            cout << "-";
        }
        cout << "Infinity\n";
    } else {
        bool sign = (P[0] * Q[0] < 0);
        int g = gcd(P[0], Q[0]);
        if (sign) {
            cout << "-";
        }
        P[0] = abs(P[0]), Q[0] = abs(Q[0]);
        cout << P[0] / g << "/" << Q[0] / g << '\n';
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
