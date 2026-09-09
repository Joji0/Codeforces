// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
#define lc u<<1
#define rc u<<1|1
const int N=3000005;
int n;
int64_t seg[N<<2][2],a[N];
vector<int64_t>c;
void pull(int u, int who){seg[u][who]=seg[lc][who]+seg[rc][who];}
void build(int u, int l, int r, int who)
{
        if(l==r)
        {
                seg[u][who]=a[l];
                return;
        }
        int mid=(l+r)>>1;
        build(lc,l,mid,who);
        build(rc,mid+1,r,who);
        pull(u,who);
}
void upd(int u, int l, int r, int x, int64_t v, int who)
{
        if(l==r)
        {
                seg[u][who]+=v;
                return;
        }
        int mid=(l+r)>>1;
        if(x<=mid)upd(lc,l,mid,x,v,who);
        else upd(rc,mid+1,r,x,v,who);
        pull(u,who);
}
int64_t qry(int u, int l, int r, int ql, int qr, int who)
{
        if(ql>qr)return 0;
        if(ql<=l&&r<=qr)return seg[u][who];
        int mid=(l+r)>>1;
        int64_t ret=0;
        if(ql<=mid)ret+=qry(lc,l,mid,ql,qr,who);
        if(mid<qr)ret+=qry(rc,mid+1,r,ql,qr,who);
        return ret;
}
int get(int64_t v){return lower_bound(c.begin(),c.end(),v)-c.begin()+1;}
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                c.push_back(a[i]-1);
                c.push_back(a[i]);
                c.push_back(a[i]+1);
        }
        sort(c.begin(),c.end());
        c.erase(unique(c.begin(),c.end()),c.end());
        int64_t ans=0;
        int m=(int)c.size();
        for(int i=1;i<=n;i++)upd(1,1,m,get(a[i]),1,1);
        for(int i=1;i<=n;i++)
        {
                ans+=qry(1,1,m,get(a[i]+1),m,0)*qry(1,1,m,1,get(a[i]-1),1);
                upd(1,1,m,get(a[i]),1,0);
                upd(1,1,m,get(a[i]),-1,1);
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
