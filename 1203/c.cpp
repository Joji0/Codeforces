#include <bits/stdc++.h>
using namespace std;

// tau(n) = number of divisors
int64_t tau(int64_t n) {
    int64_t res = 1;
    for (int64_t p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int e = 0;
            while (n % p == 0) {
                n /= p;
                e++;
            }
            res *= (e + 1);
        }
    }
    if (n > 1)
        res *= 2;
    return res;
}

// sigma(n) = sum of divisors
int64_t sigma(int64_t n) {
    int64_t res = 1;
    for (int64_t p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int64_t cur = 1, pw = 1;
            while (n % p == 0) {
                n /= p;
                pw *= p;
                cur += pw;
            }
            res *= cur;
        }
    }
    if (n > 1)
        res *= (1 + n);
    return res;
}

void solve() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for (auto &x : A)
        cin >> x;
    int64_t g = A[0];
    for (int i = 1; i < N; i++) {
        g = gcd(g, A[i]);
    }
    cout << tau(g) << '\n';
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
