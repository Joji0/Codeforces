#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
using Mint=ModInt<998244353>;
int n,m,vis[1<<20],dis[1<<20],co;
vector<int>G[1<<20];
Mint wh,bl;
void dfs1(int v, int p, int dd)
{
        if(vis[v])return;
        vis[v]=true;
        dis[v]=dd;
        for(int nxt:G[v])
        {
                if(nxt==p)continue;
                if(vis[nxt])
                {
                        co|=((dd-dis[nxt]+1)&1);
                }
                if(!vis[nxt])dfs1(nxt,v,dd+1);
        }
}
void bp(int v, int c)
{
        if(vis[v])return;
        vis[v]=true;
        if(!c)wh+=1;
        else bl+=1;
        for(int nxt:G[v])
        {
                if(!vis[nxt])
                {
                        bp(nxt,c^1);
                }
        }
}
void solve() 
{
        cin>>n>>m;
        for(int i=0;i<n;i++)G[i].clear(),vis[i]=false,dis[i]=0;
        for(int i=0;i<m;i++)
        {
                int u,v;cin>>u>>v;u--,v--;
                G[u].push_back(v),G[v].push_back(u);
        }
        co=0;
        for(int i=0;i<n;i++)if(!vis[i])dfs1(i,-1,0);
        for(int i=0;i<n;i++)vis[i]=false;
        Mint ans=1;
        for(int i=0;i<n;i++)if(!vis[i]){wh=0,bl=0;bp(i,0);ans*=Mint(2).pow(wh.value())+Mint(2).pow(bl.value());}
        if(co){cout<<"0\n";return;}
        cout<<ans<<'\n';
}
int main() {
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
