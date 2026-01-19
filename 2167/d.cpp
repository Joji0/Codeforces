#include <bits/stdc++.h>
using namespace std;

const int maxN = 100;

bool prime[maxN];
vector<int> primes;

void precompute() {
    for (int i = 0; i < maxN; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int64_t i = 2; i < maxN; i++) {
        for (int64_t j = i * i; j < maxN; j += i) {
            prime[j] = false;
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
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    for (auto &x : primes) {
        for (int i = 0; i < N; i++) {
            if (A[i] % x) {
                cout << x << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
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
