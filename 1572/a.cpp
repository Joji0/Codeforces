// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>G[N];
int n,ans,deg[N],dp[N];
vector<int>topo()
{
        vector<int>ret;
        queue<int>q;
        for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
        while(!q.empty())
        {
                int u=q.front();q.pop();
                ret.push_back(u);
                for(int v:G[u])
                {
                        if(--deg[v]==0)q.push(v);
                        dp[v]=max(dp[v],dp[u]+(bool)(v<u));
                        ans=max(ans,dp[v]);
                }
        }
        return ret;
}
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)G[i].clear(),deg[i]=0,dp[i]=1;;
        for(int i=1;i<=n;i++)
        {
                int k;cin>>k;
                deg[i]=k;
                for(int j=0;j<k;j++)
                {
                        int p;cin>>p;
                        G[p].push_back(i);
                }
        }
        ans=1;
        vector<int>res=topo();
        if((int)res.size()!=n)cout<<"-1\n";
        else cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
