// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int64_t v[N],pref[N],t,ans=0;
int pr[N],node=0,root=0,lc[N],rc[N],sub[N],n;
mt19937 rng(1337);
int make(int64_t val)
{
        int u=++node;
        v[u]=val;
        pr[u]=rng();
        lc[u]=rc[u]=0;
        sub[u]=1;
        return u;
}
void pull(int u)
{
        if(u)sub[u]=sub[lc[u]]+sub[rc[u]]+1;
}
void split(int u, int64_t k, int &x, int &y)
{
        if(!u)
        {
                x=y=0;
                return;
        }
        if(v[u]<k)
        {
                x=u;
                split(rc[u],k,rc[u],y);
        }
        else
        {
                y=u;
                split(lc[u],k,x,lc[u]);
        }
        pull(u);
}
void merge(int &u, int x, int y)
{
        if(!x||!y)
        {
                u=(x?x:y);
                return;
        }
        if(pr[x]>pr[y])
        {
                u=x;
                merge(rc[u],rc[x],y);
        }
        else
        {
                u=y;
                merge(lc[u],x,lc[y]);
        }
        pull(u);
}
int order(int64_t v)
{
        int x,y;
        split(root,v,x,y);
        int ret=sub[x];
        merge(root,x,y);
        return ret;
}
void insert(int64_t v)
{
        int x,y;
        split(root,v,x,y);
        int nw=make(v);
        merge(root,x,nw);
        merge(root,root,y);
}
void solve()
{
        cin>>n>>t;
        insert(0);
        for(int i=1;i<=n;i++)
        {
                int64_t a;cin>>a;
                pref[i]=pref[i-1]+a;
                int64_t v=pref[i]-t+1;
                ans+=node-order(v);
                insert(pref[i]);
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
