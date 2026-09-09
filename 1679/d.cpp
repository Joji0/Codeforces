// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],deg[N],dp[N],maxi;
int64_t k;
vector<int>G[N];
int go(int64_t v)
{
        int node=0;
        for(int i=1;i<=n;i++)
        {
                deg[i]=0;
                if(a[i]<=v)dp[i]=1,node++;
                else dp[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
                if(a[i]>v)continue;
                for(int u:G[i])if(a[u]<=v)deg[u]++;
        }
        int mx=(bool)node;
        auto topo=[&]()->vector<int>
        {
                vector<int>res;
                queue<int>q;
                for(int i=1;i<=n;i++)if(a[i]<=v&&deg[i]==0)q.push(i),res.push_back(i);
                while(!q.empty())
                {
                        int u=q.front();q.pop();
                        for(int nxt:G[u])
                        {
                                if(a[nxt]>v)continue;
                                if(--deg[nxt]==0)
                                {
                                        q.push(nxt);
                                        res.push_back(nxt);
                                }
                                dp[nxt]=max(dp[nxt],dp[u]+1);
                                mx=max(mx,dp[nxt]);
                        }
                }
                return res;
        };
        if((int)topo().size()!=node)return 1;
        return mx>=k;
}
void solve()
{
        cin>>n>>m>>k;
        maxi=0;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                maxi=max(maxi,a[i]);
        }
        for(int i=0;i<m;i++)
        {
                int u,v;cin>>u>>v;
                G[u].push_back(v);
        }
        int l=1,r=maxi,ans=-1;
        while(l<=r)
        {
                int md=(l+r)>>1;
                if(go(md))
                {
                        ans=md;
                        r=md-1;
                }
                else l=md+1;
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
