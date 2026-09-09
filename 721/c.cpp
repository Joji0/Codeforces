// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,deg[N],from=-1,mx=-1;
int T,dp[N][N],par[N][N];
vector<array<int64_t,2>>G[N];
void topo()
{
        queue<int>q;
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++)dp[i][j]=1<<30;
                if(deg[i]==0)q.push(i);
        }
        dp[1][1]=0;
        while(!q.empty())
        {
                int u=q.front();q.pop();
                for(auto a:G[u])
                {
                        int64_t v=a[0],t=a[1];
                        if(--deg[v]==0)q.push(v);
                        for(int j=1;j<n;j++)
                        {
                                if(dp[u][j]<1<<30)
                                {
                                        int64_t nxt=dp[u][j]+t;
                                        if(nxt>(int64_t)T)continue;
                                        if(dp[u][j]+t<dp[v][j+1])
                                        {
                                                dp[v][j+1]=dp[u][j]+t;
                                                par[v][j+1]=u;
                                                if(j+1>mx&&v==n)
                                                {
                                                        mx=j+1;
                                                        from=v;
                                                }
                                        }
                                }
                        }
                }
        }
}
void go()
{
        assert(from==n&&mx!=-1);
        vector<int>res;
        while(mx>0)
        {
                res.push_back(from);
                from=par[from][mx];
                mx--;
        }
        reverse(res.begin(),res.end());
        cout<<(int)res.size()<<'\n';
        for(int x:res)cout<<x<<" ";
        cout<<'\n';
}
void solve()
{
        cin>>n>>m>>T;
        for(int i=0;i<m;i++)
        {
                int u,v;int64_t t;cin>>u>>v>>t;
                G[u].push_back({v,t});
                deg[v]++;
        }
        topo();
        go();
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
