#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000067;

bool prime[maxN];

void sieve() {
    for (int i = 0; i < maxN; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (int64_t i = 2; i < maxN; i++) {
        if (prime[i]) {
            for (int64_t j = i * i; j < maxN; j += i) {
                prime[j] = false;
            }
        }
    }
}

void solve() {
    int N, E;
    cin >> N >> E;
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        bool ok = prime[A[i]], on = false;
        bool isOne = (A[i] == 1);
        if (!ok && !isOne) {
            continue;
        }
        for (int k = 1; i + E * k < N; k++) {
            if (isOne) {
                if (prime[A[i + E * k]]) {
                    on = true;
                } else if (A[i + E * k] == 1 && !on) {
                    ans--;
                } else {
                    break;
                }
            } else {
                if (A[i + E * k] == 1) {
                } else {
                    break;
                }
            }
            ans++;
        }
    }
    cout << ans << '\n';
    for (auto &x : A) {
        cerr << prime[x] << " ";
    }
    cerr << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
