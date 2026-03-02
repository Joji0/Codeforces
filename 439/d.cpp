#include <bits/stdc++.h>
using namespace std;
int n,m;
int64_t a[1<<17],b[1<<17],l,r,ans=1LL<<60,mda,mdb;
int64_t rt(int64_t tr)
{
        int64_t ret=0;
        for(int i=0;i<n;i++)if(a[i]<tr)ret+=tr-a[i];
        for(int i=0;i<m;i++)if(b[i]>tr)ret+=b[i]-tr;
        return ret;
}
void solve() 
{
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        l=0,r=1LL<<31;
        while(r-l>=3)
        {
                mda=l+(r-l)/3,mdb=r-(r-l)/3;
                if(rt(mda)<=rt(mdb))r=mdb;
                else l=mda;
        }
        for(int64_t i=l;i<=r;i++)
        {
                ans=min(ans,rt(i));
        }
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
