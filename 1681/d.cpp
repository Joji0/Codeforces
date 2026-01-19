#include <bits/stdc++.h>
using namespace std;

string mult(const string &s, int d) {
    int carry = 0;
    string ret;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        int x = (s[i] - '0') * d + carry;
        ret.push_back(char('0' + x % 10));
        carry = x / 10;
    }
    while (carry) {
        ret.push_back(char('0' + carry % 10));
        carry /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

void solve() {
    int n;
    uint64_t x;
    cin >> n >> x;
    if ((int)to_string(x).size() == n) {
        cout << "0\n";
        return;
    }
    bool ok = false;
    for (auto &ch : to_string(x)) {
        if (ch - '0' >= 2) {
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << "-1\n";
        return;
    }
    queue<string> q;
    map<string, int> dist;
    q.push(to_string(x));
    while (!q.empty()) {
        string now = q.front();
        int d = dist[now];
        q.pop();
        if ((int)now.size() == n) {
            cout << d << '\n';
            return;
        }
        set<char> st(now.begin(), now.end());
        for (auto &ch : st) {
            string got = mult(now, ch - '0');
            if (dist.contains(got))
                continue;
            q.push(got);
            dist[got] = d + 1;
        }
    }
    cout << "-1\n";
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
