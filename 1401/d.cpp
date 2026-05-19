#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
using Mint=ModInt<1000000007>;
int n,m,p[1<<17];
int64_t sub[1<<17],dp[1<<17];
vector<int>T[1<<17];
map<array<int,2>,int>mp;
vector<array<int,2>>vis;
void dfs(int v, int p)
{
        sub[v]=1;
        for(int u:T[v])
        {
                if(u==p)continue;
                else 
                {
                        dfs(u,v);
                        sub[v]+=sub[u];
                        vis.push_back({v,u});
                }
        }
}
void solve() 
{
        mp.clear(),vis.clear();
        cin>>n;
        for(int i=0;i<=n;i++)sub[i]=0,dp[i]=0;
        for(int i=0;i<=n;i++)T[i].clear();
        for(int i=1;i<=n-1;i++)
        {
                int u,v;cin>>u>>v;
                T[u].push_back(v),T[v].push_back(u);
                if(u>v)swap(u,v);
                mp[{u,v}]=i;
        }
        cin>>m;
        for(int i=1;i<=m;i++)cin>>p[i];
        dfs(1,-1);
        for(auto&[f,t]:vis)
        {
                if(mp.count({f,t}))
                {
                        dp[mp[{f,t}]]=sub[t]*(n-sub[t]);
                }
                else 
                {
                        dp[mp[{t,f}]]=sub[t]*(n-sub[t]);
                }
        }
        sort(dp+1,dp+n);
        sort(p+1,p+m+1);
        Mint ans=0;
        if(n-1<m)
        {
                for(int i=1;i<=n-2;i++)
                {
                        ans+=Mint(dp[i])*Mint(p[i]);
                }
                Mint extra=1;
                for(int i=n-1;i<=m;i++)
                {
                        extra*=Mint(p[i]);
                }
                ans+=extra*dp[n-1];
        }
        else if(n-1>m)
        {
                reverse(dp+1,dp+n);
                reverse(p+1,p+m+1);
                for(int i=1;i<=m;i++)
                {
                        ans+=Mint(dp[i])*Mint(p[i]);
                }
                for(int i=m+1;i<=n-1;i++)ans+=dp[i];
        }
        else 
        {
                for(int i=1;i<=n-1;i++)
                {
                        ans+=Mint(dp[i])*Mint(p[i]);
                }
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
