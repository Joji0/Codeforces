#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
using Mint=ModInt<998244353>;
int64_t l,r;
int k;
bool vis[20][2][1<<10][2];
struct State
{
        Mint cnt,sum;
}memo[20][2][1<<10][2];
Mint p[20];
State dp(const string &x, int idx, int tgt, int mask, bool lz)
{
        if(idx>=(int)x.size())
        {
                if(__builtin_popcount(mask)<=k)return {1,0};
                else return {0,0};
        }
        if(vis[idx][tgt][mask][lz])return memo[idx][tgt][mask][lz];
        State ans={0,0};
        int lim=tgt?x[idx]-'0':9;
        for(int i=0;i<=lim;i++)
        {
                bool nlz=lz&&(i==0);
                int nmask=nlz?mask:mask|(1<<i);
                if(__builtin_popcount(nmask)>k)continue;
                State got=dp(x,idx+1,tgt&&bool(i==lim),nmask,nlz);
                ans.cnt+=got.cnt;
                ans.sum+=i*p[(int)x.size()-idx-1]*got.cnt+got.sum;
        }
        vis[idx][tgt][mask][lz]=true;
        memo[idx][tgt][mask][lz]=ans;
        return ans;
}
void solve()
{
        cin>>l>>r>>k;
        memset(vis,0,sizeof(vis));
        memset(memo,0,sizeof(memo));
        Mint R=dp(to_string(r),0,1,0,1).sum;
        memset(vis,0,sizeof(vis));
        memset(memo,0,sizeof(memo));
        Mint L=dp(to_string(l-1),0,1,0,1).sum;
        cout<<Mint(R-L)<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        p[0]=1;
        for(int i=1;i<20;i++)p[i]=Mint(10)*p[i-1];
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
