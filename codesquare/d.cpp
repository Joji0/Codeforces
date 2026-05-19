#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,q,d[MAXN],pth[MAXN];
static int64_t a[MAXN],up[MAXN][20],mx[MAXN][20],mn[MAXN][20];
vector<int>T[MAXN];
array<int64_t,2>qry(int u, int v)
{
        int64_t rmx=max(a[u],a[v]),rmn=min(a[u],a[v]);
        if(d[u]<d[v])swap(u,v);
        int k=d[u]-d[v];
        for(int j=19;j>=0;j--)
        {
                if((k>>j)&1)
                {
                        rmx=max(rmx,mx[u][j]);
                        rmn=min(rmn,mn[u][j]);
                        u=up[u][j];
                }
        }
        if(u==v)return{rmx,rmn};
        for(int j=19;j>=0;j--)
        {
                if(up[u][j]!=up[v][j])
                {
                        rmx=max({rmx,mx[u][j],mx[v][j]});
                        rmn=min({rmn,mn[u][j],mn[v][j]});
                        u=up[u][j],v=up[v][j];
                }
        }
        rmx=max({rmx,mx[u][0],mx[v][0]});
        rmn=min({rmn,mn[u][0],mn[v][0]});
        return{rmx,rmn};
}
void dfs(int v, int p)
{
        if(p==-1)p=v;
        up[v][0]=p;
        mx[v][0]=max(a[v],a[p]);
        mn[v][0]=min(a[v],a[p]);
        for(int j=1;j<20;j++)
        {
                up[v][j]=up[up[v][j-1]][j-1];
                mx[v][j]=max(mx[v][j-1],mx[up[v][j-1]][j-1]);
                mn[v][j]=min(mn[v][j-1],mn[up[v][j-1]][j-1]);
        }
        for(int u:T[v])if(u!=p)
        {
                d[u]=d[v]+1;
                dfs(u,v);
        }
}
void solve()
{
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;
                T[u].push_back(v),T[v].push_back(u);
        }
        dfs(1,-1);
        while(q--)
        {
                int64_t mxx=-1LL<<60,mnn=1LL<<60;
                int k;cin>>k;
                for(int i=0;i<k;i++)cin>>pth[i];
                for(int i=0;i<k;i++)
                {
                        if(i==0)
                        {
                                auto f=qry(1,pth[0]);
                                mxx=max(mxx,f[0]),mnn=min(mnn,f[1]);
                        }
                        else
                        {
                                auto f=qry(pth[i-1],pth[i]);
                                mxx=max(mxx,f[0]),mnn=min(mnn,f[1]);
                        }
                }
                cout<<mxx-mnn<<'\n';
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
