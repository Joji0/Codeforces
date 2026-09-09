#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
using Mint=ModInt<998244353>;
const int N=300005;
int n;
int64_t a[N],pref[N];
Mint c[31][2],s[31][2];
void solve()
{
        for(int i=0;i<31;i++)c[i][0]=1;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                pref[i]=pref[i-1]^a[i];
        }
        Mint ans=0;
        for(int i=1;i<=n;i++)
        {
                for(int bit=0;bit<31;bit++)
                {
                        int nw=(pref[i]>>bit)&1;
                        int nd=nw^1;
                        ans+=(Mint(1LL<<bit))*(Mint(i)*c[bit][nd]-s[bit][nd]);
                        c[bit][nw]+=1;
                        s[bit][nw]+=i;
                }
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
