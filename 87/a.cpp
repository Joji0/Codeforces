#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t A, B;
    cin >> A >> B;
    int64_t l = lcm(A, B);
    int gA = l / A, gB = l / B;
    if (abs(gA - gB) == 1) {
        cout << "Equal\n";
    } else if (gA > gB) {
        cout << "Dasha\n";
    } else {
        cout << "Masha\n";
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
