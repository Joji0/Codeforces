#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
vector<array<ll,2>>g[300005];
ll w[300005],dp[300005],ans=-1ll<<60;
void dfs(int u, int p)
{
        ll mx1=0,mx2=0;
        for(auto [v,c]:g[u])
        {
                if(v==p)continue;
                dfs(v,u);
                if(dp[v]-c>=mx1)
                {
                        mx2=mx1;
                        mx1=dp[v]-c;
                }
                else if(dp[v]-c>mx2)mx2=dp[v]-c;
        }
        dp[u]=max(dp[u],w[u]+mx1);
        ans=max(ans,w[u]+mx1+mx2);
}
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>w[i];
        for(int i=0;i<n-1;i++)
        {
                int u,v;ll c;cin>>u>>v>>c;u--,v--;
                g[u].push_back({v,c});
                g[v].push_back({u,c});
        }
        dfs(0,-1);
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
