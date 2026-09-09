// 我思う、故に我在り
#include <bits/stdc++.h>
#include "ds/segtree/segtree.hpp"

void solve() {
        int N, M, Q; std::cin >> N >> M >> Q;
        struct FastDSU {
                int parent[40];
                FastDSU() { for (int i = 0; i < 40; i++) parent[i] = i; }
                int find(int x) { return (x == parent[x] ? x : parent[x] = find(parent[x])); }
                bool join(int a, int b) {
                        a = find(a), b = find(b);
                        if (a != b) {
                                parent[a] = b;
                                return true;
                        }
                        return false;
                }
        };
        struct DSU_Node {
                int n, comps;
                int l_val[10], r_val[10], l_id[10], r_id[10];
                DSU_Node(int _n = 0) {
                        n = _n;
                        comps = 0;
                }
        };
        struct Monoid {
                using value_type = DSU_Node;
                static value_type e() { return DSU_Node(); }
                static value_type op(const value_type &a, const value_type &b) {
                        if (a.n == 0) return b;
                        if (b.n == 0) return a;
                        DSU_Node ret(a.n);
                        ret.comps = a.comps + b.comps;
                        for (int i = 0; i < a.n; i++) {
                                ret.l_val[i] = a.l_val[i];
                                ret.r_val[i] = b.r_val[i];
                        }
                        FastDSU dsu;
                        for (int i = 0; i < a.n; i++) {
                                if (a.r_val[i] == b.l_val[i]) {
                                        if (dsu.join(a.r_id[i], b.l_id[i] + 20)) {
                                                ret.comps--;
                                        }
                                }
                        }
                        int map[40];
                        std::fill(map, map + 40, -1);
                        int id = 0;
                        for (int i = 0; i < a.n; i++) {
                                int root = dsu.find(a.l_id[i]);
                                if (map[root] == -1) map[root] = id++;
                                ret.l_id[i] = map[root];
                        }
                        for (int i = 0; i < a.n; i++) {
                                int root = dsu.find(b.r_id[i] + 20);
                                if (map[root] == -1) map[root] = id++;
                                ret.r_id[i] = map[root];
                        }
                        return ret;
                }
        };
        std::vector<std::vector<int>> G(N, std::vector<int>(M));
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) std::cin >> G[i][j];
        std::vector<DSU_Node> init(M);
        for (int j = 0; j < M; j++) {
                init[j] = DSU_Node(N);
                for (int i = 0; i < N; i++) {
                        init[j].l_val[i] = init[j].r_val[i] = G[i][j];
                        if (i - 1 >= 0 && G[i][j] == G[i - 1][j]) {
                                init[j].l_id[i] = init[j].l_id[i - 1];
                        } else {
                                init[j].l_id[i] = i;
                                init[j].comps++;
                        }
                }
                for (int i = 0; i < N; i++) init[j].r_id[i] = init[j].l_id[i];
        }
        SegTree<Monoid> seg(init);
        while (Q--) {
                int l, r; std::cin >> l >> r; l--, r--;
                DSU_Node ans = seg.query(l, r);
                std::cout << ans.comps << '\n';
        }
}

int main() {
        std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int tc = 1;
        // std::cin >> tc;
	while (tc--) solve();
	return 0;
}
