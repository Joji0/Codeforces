#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;
    int64_t s1 = 0, s2 = 0, base = 0;
    int n = 0;
    deque<int64_t> dq1, dq2;
    while (q--) {
        int s;
        cin >> s;
        if (s == 1) {
            int64_t back = dq1.back();
            dq1.pop_back();
            dq1.push_front(back);
            s1 += base - back;
            s1 -= back * n;
            s1 += back;
            back = dq2.front();
            dq2.pop_front();
            dq2.push_back(back);
            s2 -= base - back;
            s2 += back * n;
            s2 -= back;
        } else if (s == 2) {
            swap(s1, s2);
            swap(dq1, dq2);
        } else {
            int64_t k;
            cin >> k;
            n++;
            dq1.push_back(k);
            dq2.push_front(k);
            s1 += k * n;
            s2 += base + k;
            base += k;
        }
        cout << s1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
