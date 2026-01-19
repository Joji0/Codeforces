#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1000000007;

struct matrix {
    int sz;
    vector<vector<int64_t>> m;
    matrix(int n, bool ok = false) : sz(n) {
        m.assign(sz, vector<int64_t>(sz, 0));
        if (ok) {
            for (int i = 0; i < sz; i++) {
                for (int j = 0; j < sz; j++) {
                    m[i][j] = (i == j);
                }
            }
        }
    }
    friend matrix operator*(const matrix &a, const matrix &b) {
        int sz = a.sz;
        matrix c(sz);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                c.m[i][j] = 0;
                for (int k = 0; k < sz; k++) {
                    c.m[i][j] += ((a.m[i][k] % MOD) * (b.m[k][j] % MOD)) % MOD;
                    c.m[i][j] %= MOD;
                }
            }
        }
        return c;
    }
};

matrix matexp(matrix base, int64_t n) {
    int sz = base.sz;
    matrix ans(sz, true);
    while (n) {
        if (n & 1) {
            ans = ans * base;
        }
        base = base * base;
        n >>= 1;
    }
    return ans;
}

void solve() {
    /*
     * observation: Hmmmm can this be reduced to a well known problem? (idk lets
     * give it a try) Let's make a directed graph with matrix representation
     * (not adjacency list!) mat[i][j] = 1 denotes there's a way from i to j
     * else 0. Then for a restricted nucleotide pair a and b, we set mat[a][b] =
     * 0. Then this is a well known problem from graph theory, we can actually
     * see the number of path with length N as the matrix ^ N and get the answer
     * as the sum of the number inside of them.
     */
    int64_t N, M, K;
    cin >> N >> M >> K;
    matrix mat(M);
    auto idx = [](const char &ch) -> int {
        if ('a' <= ch && ch <= 'z') {
            return ch - 'a';
        } else if ('A' <= ch && ch <= 'Z') {
            return ch - 'A' + 26;
        } else {
            assert(false);
        }
    };
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            mat.m[i][j] = 1;
        }
    }
    while (K--) {
        char ch1, ch2;
        cin >> ch1 >> ch2;
        int id1 = idx(ch1), id2 = idx(ch2);
        mat.m[id1][id2] = 0;
    }
    if (N == 1) {
        cout << M << '\n';
        return;
    }
    matrix f = matexp(mat, N - 1);
    int64_t ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            ans += f.m[i][j] % MOD;
            ans %= MOD;
        }
    }
    cout << ans << '\n';
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
