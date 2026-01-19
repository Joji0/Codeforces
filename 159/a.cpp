#include <bits/stdc++.h>
using namespace std;

struct Info {
    string a, b;
    int t;
};

void solve() {
    int n, d;
    cin >> n >> d;
    vector<Info> A(n);
    set<array<string, 2>> ans;
    for (int i = 0; i < n; i++) {
        cin >> A[i].a >> A[i].b >> A[i].t;
    }
    for (int i = 0; i < n; i++) {
        string s = A[i].a, r = A[i].b;
        int nt = A[i].t;
        for (int j = i + 1; j < n; j++) {
            if (A[j].a == r && A[j].b == s && A[j].t > nt && A[j].t - nt <= d) {
                auto pair = minmax(A[j].a, A[j].b);
                ans.insert({pair.first, pair.second});
                break;
            }
        }
    }
    cout << (int)ans.size() << '\n';
    for (auto &x : ans) {
        cout << x[0] << " " << x[1] << '\n';
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
