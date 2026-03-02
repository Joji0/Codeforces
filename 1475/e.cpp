#include "mod/combinatorics.hpp"
#include "mod/modint.hpp"
#include <bits/stdc++.h>
using namespace std;

void solve() {
        using Mint = ModInt<1000000007>;
        using COMB = Combinatorics<Mint>;
        int N, K;
        cin >> N >> K;
        vector<int> A(N), top_K;
        for (auto &x : A) cin >> x;
        top_K = A;
        sort(top_K.rbegin(), top_K.rend());
        top_K.resize(K);
        int check = top_K.back(), tot = count(A.begin(), A.end(), check),
            need = count(top_K.begin(), top_K.end(), check);
        cout << COMB::C(tot, need) << '\n';
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1;
        cin >> t;
        while (t--) solve();

        return 0;
}
