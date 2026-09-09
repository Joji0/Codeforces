#line 1 "e2.cpp"
#include <bits/stdc++.h>
#line 5 "mod/modint.hpp"

template <uint32_t MOD> struct ModInt
{
        static_assert(MOD > 1, "MOD must be > 1");
        uint32_t val;
        static uint32_t mod() { return MOD; }
        constexpr ModInt() : val(0) {}
        constexpr ModInt(const int64_t &x) : val(x >= 0 ? x % MOD : (MOD - (-x) % MOD) % MOD) {}
        constexpr uint32_t value() const { return val; }
        constexpr ModInt &operator+=(const ModInt &rhs)
        {
                val += rhs.val;
                if (val >= MOD) val -= MOD;
                return *this;
        }
        constexpr ModInt &operator-=(const ModInt &rhs)
        {
                if (val < rhs.val) val += MOD;
                val -= rhs.val;
                return *this;
        }
        constexpr ModInt &operator*=(const ModInt &rhs)
        {
                val = (uint64_t)val * rhs.val % MOD;
                return *this;
        }
        constexpr ModInt &operator/=(const ModInt &rhs) { return *this *= rhs.inverse(); }
        constexpr ModInt operator+() const { return *this; }
        constexpr ModInt operator-() const { return ModInt(val == 0 ? 0 : MOD - val); }
        friend constexpr ModInt operator+(ModInt lhs, const ModInt &rhs) { return lhs += rhs; }
        friend constexpr ModInt operator-(ModInt lhs, const ModInt &rhs) { return lhs -= rhs; }
        friend constexpr ModInt operator*(ModInt lhs, const ModInt &rhs) { return lhs *= rhs; }
        friend constexpr ModInt operator/(ModInt lhs, const ModInt &rhs) { return lhs /= rhs; }
        friend constexpr bool operator==(const ModInt &lhs, const ModInt &rhs) { return lhs.val == rhs.val; }
        friend constexpr bool operator!=(const ModInt &lhs, const ModInt &rhs) { return lhs.val != rhs.val; }
        constexpr ModInt pow(uint64_t n) const
        {
                ModInt res = 1, a = *this;
                while (n > 0)
                {
                        if (n & 1) res *= a;
                        a *= a;
                        n >>= 1;
                }
                return res;
        }
        constexpr ModInt inverse() const
        {
                int64_t a = val, b = MOD, u = 1, v = 0;
                while (b)
                {
                        int64_t t = a / b;
                        a -= t * b;
                        std::swap(a, b);
                        u -= t * v;
                        std::swap(u, v);
                }
                return ModInt(u);
        }
        friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { return os << x.val; }
        friend std::istream &operator>>(std::istream &is, ModInt &x)
        {
                int64_t v;
                is >> v;
                x = ModInt(v);
                return is;
        }
};
#line 6 "mod/combinatorics.hpp"

template <typename Mint> struct Combinatorics
{
        struct Storage
        {
                std::vector<Mint> fact, inv, invfact, der;
                Storage()
                {
                        fact = {Mint(1), Mint(1)};
                        inv = {Mint(0), Mint(1)};
                        invfact = {Mint(1), Mint(1)};
                        der = {Mint(1), Mint(0)};
                }
                void extend(int n)
                {
                        if (n < (int)fact.size()) return;
                        int target = std::max(n + 1, (int)fact.size() * 2);
                        int curr = (int)fact.size();
                        int MOD = Mint::mod();
                        fact.resize(target);
                        inv.resize(target);
                        invfact.resize(target);
                        der.resize(target);
                        for (int i = curr; i < target; i++)
                        {
                                fact[i] = fact[i - 1] * Mint(i);
                                if (i < MOD)
                                {
                                        inv[i] = inv[MOD % i] * Mint(MOD - MOD / i);
                                }
                                else
                                {
                                        inv[i] = Mint(i).inverse();
                                }
                                invfact[i] = invfact[i - 1] * inv[i];
                                der[i] = Mint(i - 1) * (der[i - 1] + der[i - 2]);
                        }
                }
        };
        static Storage &data()
        {
                static Storage s;
                return s;
        }
        static void ensure(int n) { data().extend(n); }
        static Mint fact(int n)
        {
                if (n < 0) return Mint(0);
                ensure(n);
                return data().fact[n];
        }
        static Mint inv(int n)
        {
                if (n < 0) return Mint(n).inverse();
                ensure(n);
                return data().inv[n];
        }
        static Mint invfact(int n)
        {
                if (n < 0) return Mint(0);
                ensure(n);
                return data().invfact[n];
        }
        static Mint derangement(int n)
        {
                if (n < 0) return Mint(0);
                ensure(n);
                return data().der[n];
        }
        static Mint C(int64_t n, int64_t k)
        {
                if (k < 0 || k > n) return Mint(0);
                if (n < (int64_t)data().fact.size())
                {
                        return fact(n) * invfact(k) * invfact(n - k);
                }
                if (n < 20000000)
                {
                        ensure(n);
                        return fact(n) * invfact(k) * invfact(n - k);
                }
                return C_large(n, k);
        }
        static Mint C_large(int64_t n, int64_t k)
        {
                if (k < 0 || k > n) return Mint(0);
                k = std::min(k, n - k);
                Mint num(1);
                for (int64_t i = 0; i < k; i++)
                {
                        num *= Mint(n - i);
                }
                return num * invfact(k);
        }
        static Mint P(int64_t n, int64_t k)
        {
                if (k < 0 || k > n) return Mint(0);
                if (n < 20000000)
                {
                        ensure(n);
                        return fact(n) * invfact(n - k);
                }
                Mint res(1);
                for (int64_t i = 0; i < k; i++)
                {
                        res *= Mint(n - i);
                }
                return res;
        }
        static Mint H(int64_t n, int64_t k)
        {
                if (n < 0 || k < 0) return Mint(0);
                if (n == 0 && k == 0) return Mint(1);
                return C(n + k - 1, k);
        }
        static Mint stars_and_bars(int64_t n, int64_t k, bool allow_empty = true)
        {
                if (k <= 0) return (n == 0 && k == 0) ? Mint(1) : Mint(0);
                if (allow_empty)
                {
                        return C(n + k - 1, k - 1);
                }
                else
                {
                        if (n < k) return Mint(0);
                        return C(n - 1, k - 1);
                }
        }
        static Mint catalan(int n)
        {
                if (n < 0) return Mint(0);
                return C(2 * n, n) * inv(n + 1);
        }
        static Mint multinomial(int n, const std::vector<int> &ks)
        {
                if (n < 0) return Mint(0);
                int64_t sum = 0;
                Mint denom(1);
                for (int k : ks)
                {
                        if (k < 0) return Mint(0);
                        sum += k;
                        denom *= invfact(k);
                }
                if (sum != n) return Mint(0);
                return fact(n) * denom;
        }
};
#line 4 "e2.cpp"
using namespace std;
const int N=200005;
using Mint=ModInt<1000000007>;
Combinatorics<Mint>comb;
int n,m,k;
int64_t a[N];
void solve()
{
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        Mint ans=0;
        for(int i=0;i<n;i++)
        {
                auto it=upper_bound(a,a+n,a[i]+k);
                int avail=(it-a)-i;
                ans+=comb.C(avail-1,m-1);
        }
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        comb.ensure(N);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
