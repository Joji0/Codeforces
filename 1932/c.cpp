#line 2 "mod/barrett.hpp"
#include <cstdint>
#include <utility>

// reference: https://maspypy.github.io/library/mod/barrett.hpp
struct Barrett {
        uint32_t mod;
        uint64_t inv_mod;
        explicit Barrett(uint32_t m = 1) : mod(m), inv_mod((uint64_t)(-1) / m + 1) {}
        uint32_t umod() const { return mod; }
        uint32_t modulo(uint64_t z) const {
                if (mod == 1) return 0;
                uint64_t x = (uint64_t)(((__uint128_t)(z)*inv_mod) >> 64);
                uint64_t y = x * mod;
                return (uint32_t)(z - y + (z < y ? mod : 0));
        }
        uint64_t floor(uint64_t z) const {
                if (mod == 1) return z;
                uint64_t x = (uint64_t)(((__uint128_t)(z)*inv_mod) >> 64);
                uint64_t y = x * mod;
                return (z < y ? x - 1 : x);
        }
        std::pair<uint64_t, uint32_t> divmod(uint64_t z) const {
                if (mod == 1) return {z, 0};
                uint64_t x = (uint64_t)(((__uint128_t)(z)*inv_mod) >> 64);
                uint64_t y = x * mod;
                if (z < y) return {x - 1, z - y + mod};
                return {x, z - y};
        }
        uint32_t mul(uint32_t a, uint32_t b) const { return modulo((uint64_t)(a)*b); }
};
#line 3 "mod/dynamic_modint.hpp"
#include <cassert>
#line 5 "mod/dynamic_modint.hpp"
#include <iostream>
#line 7 "mod/dynamic_modint.hpp"

template <int id> struct DynamicModInt {
        static inline Barrett MOD = Barrett(998244353);
        uint32_t val;
        static void set_mod(uint32_t m) {
                assert(m > 0);
                MOD = Barrett(m);
        }
        static uint32_t mod() { return MOD.umod(); }
        DynamicModInt() : val(0) {}
        DynamicModInt(const int64_t &x)
            : val(x >= 0 ? x % MOD.umod() : (MOD.umod() - (-x) % MOD.umod()) % MOD.umod()) {}
        uint32_t value() const { return val; }
        DynamicModInt &operator+=(const DynamicModInt &rhs) {
                val += rhs.val;
                if (val >= MOD.umod()) val -= MOD.umod();
                return *this;
        }
        DynamicModInt &operator-=(const DynamicModInt &rhs) {
                if (val < rhs.val) val += MOD.umod();
                val -= rhs.val;
                return *this;
        }
        DynamicModInt &operator*=(const DynamicModInt &rhs) {
                val = MOD.mul(val, rhs.val);
                return *this;
        }
        DynamicModInt &operator/=(const DynamicModInt &rhs) { return *this *= rhs.inverse(); }
        DynamicModInt operator+() const { return *this; }
        DynamicModInt operator-() const { return DynamicModInt(val == 0 ? 0 : MOD.umod() - val); }
        friend DynamicModInt operator+(DynamicModInt lhs, const DynamicModInt &rhs) { return lhs += rhs; }
        friend DynamicModInt operator-(DynamicModInt lhs, const DynamicModInt &rhs) { return lhs -= rhs; }
        friend DynamicModInt operator*(DynamicModInt lhs, const DynamicModInt &rhs) { return lhs *= rhs; }
        friend DynamicModInt operator/(DynamicModInt lhs, const DynamicModInt &rhs) { return lhs /= rhs; }
        friend bool operator==(const DynamicModInt &lhs, const DynamicModInt &rhs) { return lhs.val == rhs.val; }
        friend bool operator!=(const DynamicModInt &lhs, const DynamicModInt &rhs) { return lhs.val != rhs.val; }
        DynamicModInt pow(uint64_t n) const {
                DynamicModInt res = 1, a = *this;
                while (n > 0) {
                        if (n & 1) res *= a;
                        a *= a;
                        n >>= 1;
                }
                return res;
        }
        DynamicModInt inverse() const {
                int64_t a = val, b = MOD.umod(), u = 1, v = 0;
                while (b) {
                        int64_t t = a / b;
                        a -= t * b;
                        std::swap(a, b);
                        u -= t * v;
                        std::swap(u, v);
                }
                return DynamicModInt(u);
        }
        friend std::ostream &operator<<(std::ostream &os, const DynamicModInt &x) { return os << x.val; }
        friend std::istream &operator>>(std::istream &is, DynamicModInt &x) {
                int64_t v;
                is >> v;
                x = DynamicModInt(v);
                return is;
        }
};
#line 2 "c.cpp"
#include <bits/stdc++.h>
using namespace std;
int n,m,a[1<<20],pl,pr;
string s;
using Mint = DynamicModInt<0>;
vector<int>o;
void solve() 
{
        o.clear();
        cin>>n>>m;
        Mint::set_mod(m);
        Mint t=Mint(1);
        vector<Mint>ans;
        for(int i=0;i<n;i++)cin>>a[i];
        cin>>s;
        pl=0,pr=n-1;
        for(char c:s)
        {
                if(c=='L')o.push_back(a[pl++]);
                else o.push_back(a[pr--]);
        }
        reverse(o.begin(),o.end());
        for(int x:o)
        {
                t*=Mint(x);
                ans.push_back(t);
        }
        reverse(ans.begin(),ans.end());
        for(Mint x:ans)
        {
                cout<<x<<" ";
        }
        cout<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
