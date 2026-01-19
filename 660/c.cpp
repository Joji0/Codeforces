#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
    int l = 0, best = 0, zer = 0, sL = -1, sR = -1;
    for (int r = 0; r < N; r++) {
        zer += !A[r];
        while (zer > K) {
            if (!A[l])
                zer--;
            l++;
        }
        if (r - l + 1 > best) {
            best = r - l + 1;
            sL = l, sR = r;
        }
    }
    cout << best << '\n';
    for (int i = 0; i < N; i++) {
        if (sL <= i && i <= sR) {
            cout << "1 ";
        } else {
            cout << A[i] << " ";
        }
    }
    cout << '\n';
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
