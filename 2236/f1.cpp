#include <bits/stdc++.h>
#include "nt/sieve.hpp"
#include "mod/modint.hpp"
using namespace std;
int n,x;
NT::Sieve sieve(1<<20);
using Mint=ModInt<1000000007>;
void solve()
{
        cin>>n>>x;
        map<int,Mint>mp;
        for(int i=0;i<n;i++)
        {
                int v;cin>>v;
                for(auto&[pr,cnt]:sieve.get_prime_factors(v))
                {
                        mp[pr]+=cnt;
                }
        }
        Mint ans=1;
        for(auto&[pr,cnt]:mp)
        {
                ans*=(cnt+1);
        }
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
