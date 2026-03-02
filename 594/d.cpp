#include "ds/segtree/segtree.hpp"
#include "mod/modint.hpp"
#include <bits/stdc++.h>
using namespace std;

void solve() {
        int N;
        cin >> N;
        using Mint = ModInt<1000000007>;
        vector<int> raw_A(N);
        vector<Mint> A(N);
        for (auto &x : raw_A) cin >> x;
        for (int i = 0; i < N; i++) A[i] = (Mint)raw_A[i];
        int Q;
        cin >> Q;
        vector<vector<array<int, 2>>> query(N);
        for (int i = 0; i < Q; i++) {
                int l, r;
                cin >> l >> r;
                l--, r--;
                query[r].push_back({l, i});
        }
        struct Monoid {
                using value_type = Mint;
                static Mint e() { return Mint(1); }
                static Mint op(const Mint &a, const Mint &b) { return a * b; }
        };
        SegTree<Monoid> seg(vector<Mint>(N, Mint(1)));
        vector<Mint> ans(Q), pref(N, Mint(1));
        for (int i = 0; i < N; i++) pref[i] = (i ? pref[i - 1] : Mint(1)) * A[i];
        const int maxA = 1000067;
        vector<int> spf(maxA), last_pos(maxA, -1);
        iota(spf.begin(), spf.end(), 0);
        auto sieve = [&]() -> void {
                for (int i = 2; i * i < maxA; i++) {
                        if (spf[i] == i) {
                                for (int j = i * i; j < maxA; j += i) {
                                        if (spf[j] == j) spf[j] = i;
                                }
                        }
                }
        };
        sieve();
        for (int i = 0; i < N; i++) {
                int val = raw_A[i];
                Mint curr = Mint(1);
                while (val > 1) {
                        int p = spf[val];
                        if (last_pos[p] != -1) {
                                seg.update(last_pos[p], seg.get(last_pos[p]) * Mint(p) / Mint(p - 1));
                        }
                        curr *= Mint(p - 1) / Mint(p);
                        last_pos[p] = i;
                        while (val % p == 0) val /= p;
                }
                seg.update(i, curr);
                for (auto &[l, idx] : query[i]) {
                        Mint raw_prod = pref[i] / (l ? pref[l - 1] : Mint(1));
                        Mint prime_prod = seg.query(l, i);
                        ans[idx] = raw_prod * prime_prod;
                }
        }
        for (auto &x : ans) {
                cout << x << '\n';
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        // cin >> t;
        while (t--) solve();

        return 0;
}
