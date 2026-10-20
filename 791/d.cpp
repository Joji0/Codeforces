#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll k,dp[200005],ans,sz[200005][5],tt[200005][5];
vector<int>T[200005];
// int root;
void go(int v, int p, ll dep)
{
        dp[1]+=(dep+k-1)/k;
        sz[v][0]=1;
        for(auto&u:T[v])
        {
                if(u==p)
                        continue;
                go(u,v,dep+1);
                for(int i=0;i<k;i++)
                        sz[v][(i+1)%k]+=sz[u][i];
        }
}
void gogo(int v, int p)
{
        for(int i=0;i<k;i++)
                tt[v][i]=sz[v][i];
        if(v!=1)
        {
                for(int i=0;i<k;i++)
                {
                        tt[v][i]+=tt[p][(i-1+k)%k];
                        tt[v][i]-=sz[v][(i-2+k)%k];
                }
                dp[v]=dp[p]-sz[v][0]+tt[p][0]-sz[v][k-1];
        }
        // cerr<<"v: "<<v<<" DP: "<<dp[v]<<'\n';
        for(auto&u:T[v])
        {
                if(u==p)
                        continue;
                gogo(u,v);
        }
}
void solve()
{
        cin>>n>>k;
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;
                T[u].push_back(v);
                T[v].push_back(u);
        }
        // for(int i=1;i<=n;i++)
        // {
        //         root=i;
        //         go(i,-1,0);
        // }
        go(1,-1,0);
        // for(int i=1;i<=n;i++)
        // {
        //         cerr<<"EVALUATING: "<<i<<'\n';
        //         for(int j=0;j<k;j++)
        //                 cerr<<sz[i][j]<<" \n"[j==k-1];
        // }
        gogo(1,-1);
        for(int i=1;i<=n;i++)
                ans+=dp[i];
        cout<<ans/2ll<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
