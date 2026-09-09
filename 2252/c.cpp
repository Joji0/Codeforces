// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
#define lc u<<1
#define rc u<<1|1
const int N=1000005;
int64_t seg[N<<2],val[N],v[N];
int n,m,cnt[N<<2];
void pull(int u)
{
        seg[u]=seg[lc]+seg[rc];
        cnt[u]=cnt[lc]+cnt[rc];
}
void upd(int u, int l, int r, int idx, int64_t x)
{
        if(l==r)
        {
                seg[u]+=x;
                cnt[u]++;
                return;
        }
        int mid=(l+r)>>1;
        if(idx<=mid)upd(lc,l,mid,idx,x);
        else upd(rc,mid+1,r,idx,x);
        pull(u);
}
int qry(int u, int l, int r, int64_t q)
{
        if(q<=0)return 0;
        if(l==r)return min((int64_t)cnt[u],(q+val[l]-1)/val[l]);
        int mid=(l+r)>>1;
        if(seg[rc]>=q)return qry(rc,mid+1,r,q);
        return cnt[rc]+qry(lc,l,mid,q-seg[rc]);
}
void solve()
{
        cin>>n>>m;
        vector<vector<int64_t>>a(n+1,vector<int64_t>(m+1));
        for(int i=1;i<=n;i++)cin>>v[i];
        int at=0;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        {
                cin>>a[i][j];
                val[++at]=a[i][j];
        }
        sort(val+1,val+at+1);
        at=unique(val+1,val+at+1)-(val+1);
        for(int i=1;i<=(at<<2);i++)seg[i]=cnt[i]=0;
        int ans=m;
        for(int i=n;i>=1;i--)
        {
                for(int j=1;j<=m;j++)
                {
                        int pos=lower_bound(val+1,val+at+1,a[i][j])-(val+1)+1;
                        upd(1,1,at,pos,a[i][j]);
                }
                if(seg[1]>=v[i])ans=min(ans,qry(1,1,at,v[i]));
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
