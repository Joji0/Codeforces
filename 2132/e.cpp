#include <bits/stdc++.h>
using namespace std;
int n,m,q,x,y,z;
int64_t a[1<<20],b[1<<20],pa[1<<20],pb[1<<20],l,r,mda,mdb,tmp,ans=0;
void solve() 
{
        cin>>n>>m>>q;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        sort(a,a+n,greater<int64_t>()),sort(b,b+m,greater<int64_t>());
        for(int i=1;i<=n;i++)pa[i]=pa[i-1]+a[i-1];
        for(int i=1;i<=m;i++)pb[i]=pb[i-1]+b[i-1];
        while(q--)
        {
                cin>>x>>y>>z;
                l=max({0,z-y,z-m}),r=min({n,x,z}),ans=0;
                while(r-l>=3)
                {
                        mda=l+(r-l)/3,mdb=r-(r-l)/3;
                        if(pa[mda]+pb[z-mda]<=pa[mdb]+pb[z-mdb])l=mda;
                        else r=mdb;
                }
                for(int i=l;i<=r;i++)
                {
                        ans=max(ans,pa[i]+pb[z-i]);
                }
                cout<<ans<<'\n';
        }
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
