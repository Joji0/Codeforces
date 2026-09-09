// 我思う、故に我在り
#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
const int N=200005,MOD=1000003;
using Mint=ModInt<MOD>;
int64_t n,a[N],b[N],cnt[32];
Mint fact[MOD];
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int64_t tt=1<<30,x=0;
        for(int i=0;i<n;i++)
        {
                int64_t curr=0;
                int64_t nw=b[i];
                while(nw>a[i])
                {
                        nw>>=1;
                        curr++;
                }
                if(nw<a[i])curr--;
                tt=min(tt,curr);
        }
        Mint ways=Mint(1);
        int64_t f=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
                int64_t op=(b[i]>>tt)-a[i];
                assert(op>=0);
                x+=op;
                f+=op;
                ways*=fact[op].inverse();
                for(int j=0;j<tt;j++)if((b[i]>>j)&1)x++,cnt[j]++;
        }
        if(f>=MOD)ways=Mint(0);
        else ways*=fact[f];
        for(int i=0;i<32;i++)
        {
                if(cnt[i]==Mint(0))continue;
                if(cnt[i]>=MOD)ways=Mint(0);
                else ways*=fact[cnt[i]];
        }
        cout<<x+tt<<" "<<ways<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        fact[0]=Mint(1);
        for(int i=1;i<MOD;i++)fact[i]=Mint(i)*fact[i-1];
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
