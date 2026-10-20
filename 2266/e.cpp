#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define inf 0x3f3f3f3f3f3f3f3f
int n,k;
ll a[200005],dp[200005],ans=0;
vector<int>p[200005];
void pre()
{
        for(int i=2;i<200005;i++)
                if(p[i].empty())
                        for(int j=i;j<200005;j+=i)
                                p[j].push_back(i);
}
void solve()
{
        cin>>n>>k;
        for(int i=1;i<=n;i++)
                cin>>a[i],dp[i]=inf;
        for(int i=0;i<=k;i++)
                dp[i]=0;
        for(int i=k+1;i<=n;i++)
                for(int j:p[i])
                        dp[i]=min(dp[i],dp[i/j]*j+1);
        ans=0;
        for(int i=1;i<=n;i++)
                ans+=dp[a[i]];
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        pre();
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
