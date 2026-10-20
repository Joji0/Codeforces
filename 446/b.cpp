#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define inf 0x3f3f3f3f3f3f3f3f
ll n,m,k,p,a[1005][1005],r[1000005],c[1000005],s,ans;
void solve()
{
        cin>>n>>m>>k>>p;
        for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                        cin>>a[i][j];
        priority_queue<ll>pqr,pqc;
        for(int i=1;i<=n;i++)
        {
                s=0;
                for(int j=1;j<=m;j++)
                        s+=a[i][j];
                pqr.push(s);
        }
        for(int j=1;j<=m;j++)
        {
                s=0;
                for(int i=1;i<=n;i++)
                        s+=a[i][j];
                pqc.push(s);
        }
        for(int i=1;i<=k;i++)
        {
                auto top=pqr.top();
                pqr.pop();
                r[i]=r[i-1]+top;
                pqr.push(top-m*p);
        }
        for(int i=1;i<=k;i++)
        {
                auto top=pqc.top();
                pqc.pop();
                c[i]=c[i-1]+top;
                pqc.push(top-n*p);
        }
        ans=-inf;
        for(int i=0;i<=k;i++)
                ans=max(ans,r[i]+c[k-i]-1ll*i*(k-i)*p);
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
