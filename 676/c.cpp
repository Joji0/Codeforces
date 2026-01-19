#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    auto gimme = [&](char targ) -> int {
        int ptrl = 0, ptrr = 0, cnt = 0, ans = 0;
        while (ptrr < n) {
            if (s[ptrr] != targ) {
                cnt++;
            }
            ptrr++;
            while (ptrl < n && cnt > k) {
                if (s[ptrl] != targ)
                    cnt--;
                ptrl++;
            }
            ans = max(ans, ptrr - ptrl);
            ptrr = max(ptrl, ptrr);
        }
        return ans;
    };
    int ansA = gimme('a'), ansB = gimme('b');
    cout << max(ansA, ansB) << '\n';
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
