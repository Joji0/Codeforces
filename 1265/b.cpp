#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p)
        cin >> x;
    vector<int> ans;
    ans.push_back(1);
    int best = 1;
    int ptrl = find(p.begin(), p.end(), 1) - p.begin(), ptrr = ptrl;
    while (1) {
        if (ptrl > 0 && ptrr < n - 1) {
            if (p[ptrl - 1] < p[ptrr + 1]) {
                best = max(best, p[ptrl - 1]);
                ptrl--;
            } else {
                best = max(best, p[ptrr + 1]);
                ptrr++;
            }
        } else if (ptrl > 0) {
            best = max(best, p[ptrl - 1]);
            ptrl--;
        } else if (ptrr < n - 1) {
            best = max(best, p[ptrr + 1]);
            ptrr++;
        } else {
            break;
        }
        if (best == ptrr - ptrl + 1) {
            ans.push_back(best);
        }
    }
    string yey(n, '0');
    for (auto &x : ans) {
        yey[x - 1] = '1';
    }
    cout << yey << '\n';
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
