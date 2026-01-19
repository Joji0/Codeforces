#include <bits/stdc++.h>
using namespace std;

void solve() {
    // either 01010 or 10101
    int A, B;
    cin >> A >> B;
    int cpA = A, cpB = B, op1 = 0, op2 = 0;
    while (cpA > 0 || cpB > 0) {
        int64_t now = (1LL << op1);
        if (op1 & 1) {
            if (cpA - now < 0)
                break;
            cpA -= (1LL << op1);
        } else {
            if (cpB - now < 0)
                break;
            cpB -= (1LL << op1);
        }
        op1++;
    }
    cpA = A, cpB = B;
    while (cpA > 0 || cpB > 0) {
        int64_t now = (1LL << op2);
        if (op2 & 1) {
            if (cpB - now < 0)
                break;
            cpB -= (1LL << op2);
        } else {
            if (cpA - now < 0)
                break;
            cpA -= (1LL << op2);
        }
        op2++;
    }
    cout << max(op1, op2) << '\n';
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
