#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

void solve() {
    int N;
    string s;
    cin >> N >> s;
    int w = 0;
    for (auto &ch : s) {
        if (ch == '+')
            w++;
    }
    int l = N - w;
    int Q;
    cin >> Q;
    while (Q--) {
        int64_t a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int l1 = 0, r1 = w;
        int64_t mx = b * l, mn = a * l;
        bool ok = false;
        while (l1 <= r1) {
            int mid1 = (l1 + r1) / 2;
            int64_t got = mid1 * b + (w - mid1) * a;
            if (mn <= got && got <= mx) {
                int l2 = 0, r2 = l;
                while (l2 <= r2) {
                    int mid2 = (l2 + r2) / 2;
                    int64_t now = mid2 * b + (l - mid2) * a;
                    if (now > got) {
                        r2 = mid2 - 1;
                    } else if (now < got) {
                        l2 = mid2 + 1;
                    } else {
                        cout << "YES\n";
                        // cerr << "MID2: " << mid2 << " " << " NOW: " << now
                        //      << '\n';
                        ok = true;
                        break;
                    }
                    // cerr << mid2 << '\n';
                }
                if (ok)
                    break;
                auto val = [&](int x) -> int64_t {
                    return (int64_t)x * b + (int64_t)(l - x) * a;
                };
                int64_t best = (l2 <= l ? val(l2) : INF);
                if (best < got) {
                    l1 = mid1 + 1;
                } else {
                    r1 = mid1 - 1;
                }
            } else if (got > mx) {
                r1 = mid1 - 1;
            } else {
                l1 = mid1 + 1;
            }
            if (ok)
                break;
        }
        if (!ok) {
            cout << "NO\n";
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
