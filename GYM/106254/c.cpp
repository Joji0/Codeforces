#include <bits/stdc++.h>
#include "nt/sieve.hpp"
using namespace std;
const int64_t MIL=10000000;
int64_t a,b;
NT::Sieve sieve(MIL+67);
void solve()
{
        cin>>a>>b;
        int ans=0;
        for(int64_t tr=0;tr*a+b<MIL;tr++)
        {
                if(sieve.is_prime(tr*a+b))ans++;
        }
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
