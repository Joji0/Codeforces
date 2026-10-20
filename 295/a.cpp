#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,k,x,y;
ll a[100005],da[100005],db[100005],pa[100005],pb[100005];
struct op
{
        int l,r;
        ll d;
}q[100005];
void solve()
{
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
                cin>>a[i];
        for(int i=1;i<=m;i++)
                cin>>q[i].l>>q[i].r>>q[i].d;
        for(int i=1;i<=k;i++)
        {
                cin>>x>>y;
                da[x]++;
                da[y+1]--;
        }
        for(int i=1;i<=m;i++)
                pa[i]=pa[i-1]+da[i];
        for(int i=1;i<=m;i++)
        {
                db[q[i].l]+=q[i].d*pa[i];
                db[q[i].r+1]-=q[i].d*pa[i];
        }
        for(int i=1;i<=n;i++)
                pb[i]=pb[i-1]+db[i];
        for(int i=1;i<=n;i++)
                cout<<a[i]+pb[i]<<" \n"[i==n];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
