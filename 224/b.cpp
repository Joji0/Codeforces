#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &x : A)
        cin >> x;
    int ptrl = 0, ptrr = 0;
    map<int, int> mp;
    while (ptrr < n && (int)mp.size() < k) {
        mp[A[ptrr]]++;
        ptrr++;
    }
    if ((int)mp.size() < k) {
        cout << "-1 -1\n";
        return;
    }
    while (ptrl < ptrr && (int)mp.size() == k) {
        mp[A[ptrl]]--;
        if (mp[A[ptrl]] == 0) {
            mp.erase(A[ptrl]);
        }
        if ((int)mp.size() < k) {
            cout << ptrl + 1 << " " << ptrr << '\n';
            return;
        }
        ptrl++;
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
