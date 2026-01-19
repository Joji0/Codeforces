#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
bool prime[maxN];

void solve() {
    for (int i = 0; i < maxN; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i < maxN; i++) {
        for (int j = i * i; j < maxN; j += i) {
            prime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 0; i < maxN; i++) {
        if (prime[i])
            primes.push_back(i);
    }
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    // for (auto &x : primes) {
    //     cerr << x << " ";
    // }
    // cerr << '\n';
    for (int i = 2; i <= n; i++) {
        if (!prime[i])
            continue;
        for (int j = 0; j < (int)primes.size() - 1; j++) {
            if (primes[j] + primes[j + 1] + 1 == i) {
                cnt++;
            }
        }
    }
    if (cnt >= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
