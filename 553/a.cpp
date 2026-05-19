#include <bits/stdc++.h>
#include "mod/modint.hpp"
#include "mod/combinatorics.hpp"
using namespace std;
using Mint = ModInt<1000000007>;

int k, c[1 << 10];
Combinatorics<Mint> comb;

void solve()
{
        cin >> k;
        for (int i = 1; i <= k; i++) cin >> c[i];
        comb.ensure(1 << 20);
        Mint dp[1 << 10];
        dp[1] = 1;
        int64_t csum = c[1];
        for (int i = 2; i <= k; i++)
        {
                dp[i] = dp[i - 1] * comb.C(csum + c[i] - 1, c[i] - 1);
                csum += c[i];
        }
        cout << dp[k] << '\n';
}

int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
