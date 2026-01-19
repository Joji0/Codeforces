#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9 + 7;
const int maxN = 2e6 + 5;

vector<int64_t> fact(maxN), invfact(maxN), inv(maxN);

int64_t mod_pow(int64_t a, int64_t e) {
    a %= MOD;
    if (a < 0)
        a += MOD;
    int64_t r = 1;
    while (e > 0) {
        if (e & 1)
            r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

// Fermat inverse (MOD must be prime, and a % MOD != 0)
int64_t mod_inv(int64_t a) {
    a %= MOD;
    if (a < 0)
        a += MOD;
    return mod_pow(a, MOD - 2);
}

// precompute fact, invfact, inv
void precompute(int n = maxN - 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invfact[n] = mod_inv(fact[n]);
    for (int i = n; i >= 1; i--)
        invfact[i - 1] = invfact[i] * i % MOD;
    inv[0] = 0;
    if (n >= 1)
        inv[1] = 1;
    int lim = n;
    for (int i = 2; i <= lim; i++) {
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
    }
}

// nCr = C(n, r) = n! / (r!(n-r)!) mod MOD
int64_t nCr(int n, int r) {
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

// nPr = P(n, r) = n! / (n-r)! mod MOD
int64_t nPr(int n, int r) {
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invfact[n - r] % MOD;
}

// Stars and Bars (allow empty bins):
// distribute n identical balls into k distinct bins => C(n + k - 1, k - 1)
int64_t stars_and_bars(int n, int k) {
    if (n < 0 || k <= 0)
        return 0;
    if (k == 1)
        return 1;
    return nCr(n + k - 1, k - 1);
}

// Stars and Bars (nonempty bins):
// distribute n identical balls into k distinct bins, each >=1 => C(n - 1, k -
// 1)
int64_t stars_and_bars_nonempty(int n, int k) {
    if (n < 0 || k <= 0)
        return 0;
    if (n < k)
        return 0;
    if (k == 1)
        return 1;
    return nCr(n - 1, k - 1);
}

// Pascal triangle
struct Pascal {
    vector<vector<int64_t>> C;
    explicit Pascal(int n) {
        C.assign(n + 1, vector<int64_t>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
    }
    int64_t get(int n, int r) const {
        if (r < 0 || r > n)
            return 0;
        return C[n][r];
    }
};

// Catalan number: Cat(n) = C(2n, n) / (n+1) mod MOD
int64_t catalan(int n) {
    if (n < 0)
        return 0;
    int64_t denom_inv;
    if (n + 1 < (int)inv.size() && inv[n + 1] != 0)
        denom_inv = inv[n + 1];
    else
        denom_inv = mod_inv(n + 1);
    return nCr(2 * n, n) * denom_inv % MOD;
}

// Derangements: D(0)=1, D(1)=0, D(n)=(n-1)(D(n-1)+D(n-2)) mod MOD
vector<int64_t> der(maxN);
void precompute_derangements(int n = maxN - 1) {
    der[0] = 1;
    if (n >= 1)
        der[1] = 0;
    for (int i = 2; i <= n; i++) {
        der[i] = (int64_t)(i - 1) * ((der[i - 1] + der[i - 2]) % MOD) % MOD;
    }
}

// Multinomial coefficient:
// ways to partition n labeled items into groups of sizes k1..km:
// n! / (k1! k2! ... km!) mod MOD
int64_t multinomial(int n, const vector<int> &k) {
    int64_t res = fact[n];
    int sum = 0;
    for (int ki : k) {
        if (ki < 0)
            return 0;
        sum += ki;
        res = res * invfact[ki] % MOD;
    }
    if (sum != n)
        return 0; // safety: invalid partition sizes
    return res;
}

template <int64_t MOD> struct ModInt {
    int64_t v;
    ModInt(int64_t _v = 0) {
        v = _v % MOD;
        if (v < 0)
            v += MOD;
    }
    ModInt &operator+=(const ModInt &o) {
        v += o.v;
        if (v >= MOD)
            v -= MOD;
        return *this;
    }
    ModInt &operator-=(const ModInt &o) {
        v -= o.v;
        if (v < 0)
            v += MOD;
        return *this;
    }
    ModInt &operator*=(const ModInt &o) {
        v = (int64_t)v * o.v % MOD;
        return *this;
    }
    friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
    ModInt pow(int64_t e) const {
        ModInt r = 1, a = *this;
        while (e > 0) {
            if (e & 1)
                r *= a;
            a *= a;
            e >>= 1;
        }
        return r;
    }
    ModInt inv() const { return pow(MOD - 2); }
    ModInt &operator/=(const ModInt &o) { return *this *= o.inv(); }
    friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }
    friend ostream &operator<<(ostream &os, const ModInt &m) {
        return os << m.v;
    }
};

using mint = ModInt<1000000007>;

void solve() {
    precompute();
    int64_t A, B, N;
    cin >> A >> B >> N;
    auto ok = [&](mint x) -> bool {
        string s = to_string(x.v);
        set<char> st(s.begin(), s.end());
        for (auto &x : st) {
            if (x - '0' != A && x - '0' != B) {
                return false;
            }
        }
        return true;
    };
    mint ans = 0;
    for (int i = 0; i <= N; i++) {
        mint sum = A * i + B * (N - i);
        if (ok(sum)) {
            ans += nCr(N, i);
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
