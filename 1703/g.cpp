// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int64_t k,dp[N][31],a[N];
void solve()
{
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=0;i<=n;i++)for(int j=0;j<31;j++)dp[i][j]=-1LL<<60;
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
                for(int j=0;j<31;j++)
                {
                        if(dp[i-1][j]>-1LL<<60)
                        {
                                dp[i][j]=dp[i-1][j]+a[i]/(1<<j)-k;
                                if(j==30)dp[i][j]=max(dp[i][j],dp[i-1][j]);
                        }
                        if(j-1>=0&&dp[i-1][j-1]>-1LL<<60)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i]/(1<<j));
                }
        }
        int64_t ans=-1LL<<60;
        for(int j=0;j<31;j++)ans=max(ans,dp[n][j]);
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
