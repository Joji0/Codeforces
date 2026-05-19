#include <bits/stdc++.h>
#include "ds/unionfind/unionfind.hpp"
using namespace std;
const int MAXN=200005,LOG=20;
int n,m,up[MAXN][LOG],d[MAXN];
int64_t ans[MAXN],mx[MAXN][LOG];;
vector<pair<int,int64_t>>T[MAXN];
struct Edge
{
        int u,v,id;
        int64_t w;
}Edges[MAXN];
void dfs(int v, int p)
{
        for(auto[u,w]:T[v])
        {
                if(u==p)continue;
                up[u][0]=v;
                mx[u][0]=w;
                for(int i=1;i<LOG;i++)
                {
                        int tmp=up[u][i-1];
                        up[u][i]=up[tmp][i-1],mx[u][i]=max(mx[u][i-1],mx[tmp][i-1]);
                }
                d[u]=d[v]+1;
                dfs(u,v);
        }
}
int64_t qry(int u, int v)
{
        int64_t ret=0;
        if(d[u]<d[v])swap(u,v);
        int k=d[u]-d[v];
        for(int i=LOG-1;i>=0;i--)
        {
                if((k>>i)&1)
                {
                        ret=max(ret,mx[u][i]);
                        u=up[u][i];
                }
        }
        if(u==v)return ret;
        for(int i=LOG-1;i>=0;i--)
        {
                if(up[u][i]!=up[v][i])
                {
                        ret=max({ret,mx[u][i],mx[v][i]});
                        u=up[u][i],v=up[v][i];
                }
        }
        return max({ret,mx[u][0],mx[v][0]});
}
set<array<int,2>>mst;
void solve()
{
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
                int u,v;
                int64_t w;
                cin>>u>>v>>w;
                Edges[i]={u,v,i,w};
        }
        UnionFind uf(n+1);
        sort(Edges,Edges+m,[](const auto &x, const auto &y){return x.w<y.w;});
        int64_t tot=0;
        for(int i=0;i<m;i++)
        {
                auto[u,v,id,w]=Edges[i];
                if(uf.join(u,v))
                {
                        tot+=w;
                        mst.insert({u,v});
                        T[u].push_back({v,w}),T[v].push_back({u,w});
                }
        }
        dfs(1,1);
        for(int i=0;i<m;i++)
        {
                auto[u,v,id,w]=Edges[i];
                if(mst.contains({u,v}))
                {
                        ans[id]=tot;
                }
                else
                {
                        ans[id]=tot-qry(u,v)+w;
                }
        }
        for(int i=0;i<m;i++)cout<<ans[i]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
