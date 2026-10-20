#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1000000007;
ll n,a[100005],b[100005],c[100005],d[100005],dp[100005],p[100005],lf[100005],l,r;
void solve()
{
        cin>>n;
        for(int i=0;i<=n;i++)
                c[i]=d[i]=dp[i]=p[i]=lf[i]=0;
        for(int i=1;i<=n;i++)
                cin>>a[i];
        for(ll i=1;i<=n;i++)
        {
                l=min(n,a[i]*i),r=min(n,(a[i]+1)*i);
                c[l]++;
                c[r]--;
        }
        d[0]=c[0];
        for(int i=1;i<n;i++)
                d[i]=d[i-1]+c[i];
        for(ll i=1;i<=n;i++)
                for(ll j=0;j<a[i];j++)
                {
                        l=j*i;
                        if(l>=n)break;
                        r=min(n,(j+1)*i);
                        lf[r]=max(lf[r],l+1);
                }
        for(int i=1;i<=n;i++)
                lf[i]=max(lf[i],lf[i-1]);
        p[0]=dp[0]=1;
        for(int i=1;i<=n;i++)
        {
                if(d[i-1])
                        dp[i]=0;
                else
                {
                        l=lf[i-1];
                        if(l<=i-1)
                                dp[i]=(p[i-1]-(l?p[l-1]:0)+mod)%mod;
                        else
                                dp[i]=0;
                }
                p[i]=(p[i-1]+dp[i])%mod;
        }
        ll ans=0;
        for(int i=lf[n];i<=n;i++)
                ans=(ans+dp[i])%mod;
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
// a_k=x -> for every i in [0,x-1], [i*k,(i+1)*k-1] must show up
