#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
 * My approach here is to consider the adjacency matrix of the complete graph
 * and from there we can reduce the problem to matrix multiplication since
 * G^n(i, j) = number of ways to get from vertex i to vertex j with walk of
 * length n.
 * */

const int64_t MOD = 1000000007;

struct matrix {
    int64_t m[4][4];
    friend matrix operator*(const matrix &a, const matrix &b) {
        matrix c;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                c.m[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    c.m[i][j] += ((a.m[i][k] % MOD) * (b.m[k][j] % MOD)) % MOD;
                    c.m[i][j] %= MOD;
                }
            }
        }
        return c;
    }
};

matrix matexp(matrix base, int64_t n) {
    matrix ans = {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};
    while (n) {
        if (n & 1) {
            ans = ans * base;
        }
        base = base * base;
        n >>= 1;
    }
    return ans;
}

int64_t get(int64_t n) {
    matrix base = {{{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}}};
    return matexp(base, n).m[0][0];
}

void solve() {
    int n;
    cin >> n;
    cout << get(n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
