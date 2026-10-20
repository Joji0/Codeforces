#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll k,dp[200005],ans,sz[200005][5];
vector<int>T[200005];
int root;
void go(int v, int p, ll dep)
{
        dp[root]+=(dep+k-1)/k;
        sz[v][0]=1;
        for(auto&u:T[v])
        {
                if(u==p)
                        continue;
                go(u,v,dep+1);
                for(int i=0;i<5;i++)
                        sz[v][(i+1)%k]+=sz[u][i];
        }
}
void gogo(int v, int p, ll dep)
{
        if(v!=1)
                dp[v]=dp[p]-(sz[v][0])+(sz[p][0]-sz[v][1]);
        cerr<<"v: "<<v<<" DP: "<<dp[v]<<'\n';
        for(auto&u:T[v])
        {
                if(u==p)
                        continue;
                // if(v!=1)
                // {
                // }
                gogo(u,v,dep+1);
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
        for(int i=1;i<=n;i++)
        {
                root=i;
                go(i,-1,0);
        }
        // go(1,-1,0);
        // for(int i=1;i<=n;i++)
        // {
        //         cerr<<"EVALUATING: "<<i<<'\n';
        //         for(int j=0;j<k;j++)
        //                 cerr<<sz[i][j]<<" \n"[j==k-1];
        // }
        // gogo(1,-1,0);
        for(int i=1;i<=n;i++)
                cerr<<"i: "<<i<<" DP: "<<dp[i]<<'\n';
        for(int i=1;i<=n;i++)
                ans+=dp[i];
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

