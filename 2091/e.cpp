#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e7 + 5;

bool prime[maxN];
vector<int> primes;

void precompute() {
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
    for (int i = 2; i < maxN; i++) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
}

void solve() {
    int N;
    cin >> N;
    int64_t ans = 0;
    for (auto &x : primes) {
        if (x > N) {
            break;
        }
        ans += (N / x);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
