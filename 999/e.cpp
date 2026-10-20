#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,s,dfn[5005],low[5005],in[5005],stk[5005],clk,top,cnt,scc[5005],sz_scc[5005],vis[5005],indeg[5005],en[5005],ans;
vector<int>g[5005];
struct edge
{
        int u,v;
}e[5005];
void go(int v)
{
        dfn[v]=low[v]=++clk;
        stk[++top]=v,in[v]=1;
        for(int u:g[v])
        {
                if(!dfn[u])
                {
                        go(u);
                        low[v]=min(low[v],low[u]);
                }
                else if(in[u])
                        low[v]=min(low[v],dfn[u]);
        }
        if(dfn[v]==low[v])
        {
                ++cnt;
                while(1)
                {
                        int u=stk[top--];
                        in[u]=0;
                        scc[u]=cnt;
                        sz_scc[cnt]++;
                        if(u==v)break;
                }
        }
}
void solve()
{
        cin>>n>>m>>s;
        for(int i=1;i<=m;i++)
        {
                cin>>e[i].u>>e[i].v;
                g[e[i].u].push_back(e[i].v);
        }
        for(int i=1;i<=n;i++)
                if(!dfn[i])
                        go(i);
        for(int eid=1;eid<=m;eid++)
        {
                int i=e[eid].u,j=e[eid].v;
                if(scc[i]!=scc[j])
                        indeg[scc[j]]++;
        }
        for(int i=1;i<=cnt;i++)
                if(i!=scc[s]&&!indeg[i])
                        ans++;
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
