#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for (auto &x : A)
        cin >> x;
    auto it = max_element(A.begin(), A.end());
    int64_t sum = 0;
    for (auto i = A.begin(); i != A.end(); i++) {
        if (i == it)
            continue;
        sum += *i;
    }
    cout << ((sum + *it) % 2 == 0 && sum >= *it ? "YES" : "NO") << '\n';
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
