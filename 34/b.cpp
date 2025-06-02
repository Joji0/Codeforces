#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> neg;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp < 0) {
            neg.push_back(abs(temp));
        }
    }
    sort(neg.rbegin(), neg.rend());
    int cnt = 0;
    for (int i = 0; i < m && i < (int)neg.size(); i++) {
        cnt += neg[i];
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
