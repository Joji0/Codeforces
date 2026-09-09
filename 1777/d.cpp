#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
using Mint=ModInt<1000000007>;
const int N=200005;
vector<int>T[N];
int n;
int64_t sz[N],d[N];
Mint ans=0;
void dfs(int u, int par)
{
        int leaf=1;
        for(int nxt:T[u])
        {
                if(nxt==par)continue;
                leaf=0;
                dfs(nxt,u);
                sz[u]+=sz[nxt];
                d[u]=max(d[u],d[nxt]);
        }
        if(leaf)d[u]=1;
        else d[u]++;
        ans+=Mint(2).pow(n-1)*Mint(d[u]);
}
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)
        {
                T[i].clear();
                sz[i]=1;
                d[i]=0;
        }
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;u--,v--;
                T[u].push_back(v);
                T[v].push_back(u);
        }
        ans=0;
        dfs(0,-1);
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
