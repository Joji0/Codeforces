#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void factorize(ll x, map<ll, ll> &div) {
    while (x % 2 == 0) {
        div[2]++;
        x /= 2;
    }
    for (ll d = 3; d * d <= x; d += 2) {
        while (x % d == 0) {
            div[d]++;
            x /= d;
        }
    }
    if (x > 1) {
        div[x]++;
    }
}

void solve() {
    ll a, b, ans = 0;
    cin >> a >> b;
    map<ll, ll> divA, divB;
    factorize(a, divA), factorize(b, divB);
    set<ll> st, can = {2, 3, 5};
    for (auto &[d, n] : divA) {
        if (st.find(d) == st.end() && can.find(d) != can.end()) {
            ans += (divB.contains(d) ? abs(n - divB[d]) : n);
            divA[d] = 0, divB[d] = 0;
            st.insert(d);
        }
    }
    for (auto &[d, n] : divB) {
        if (st.find(d) == st.end() && can.find(d) != can.end()) {
            ans += (divA.contains(d) ? abs(n - divA[d]) : n);
            divA[d] = 0, divB[d] = 0;
            st.insert(d);
        }
    }
    bool ok = true;
    for (auto &[d, n] : divA) {
        if (can.find(d) == can.end() && divB[d] != divA[d]) {
            ok = false;
            break;
        }
    }
    for (auto &[d, n] : divB) {
        if (can.find(d) == can.end() && divB[d] != divA[d]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? ans : -1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
