#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[1000005];

bool ok(int x) {
    string s = to_string(x);
    int cnt = 0;
    for (auto &ch : s) {
        if (ch - '0')
            cnt++;
    }
    if (cnt != 1) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 999999; i++) {
        a[i] = a[i - 1];
        if (ok(i))
            a[i]++;
    }

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << a[n] << '\n';
    }

    return 0;
}
