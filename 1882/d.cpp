#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,root;
ll a[200005],ans[200005],dp[200005],sub[200005];
vector<int>T[200005];
void go(int v, int p)
{
        sub[v]=1;
        for(auto&u:T[v])
        {
                if(u==p)
                        continue;
                go(u,v);
                sub[v]+=sub[u];
        }
}
void gogo(int v, int p)
{
        for(auto&u:T[v])
        {
                if(u==p)
                        continue;
                gogo(u,v);
                dp[v]+=(dp[u]+sub[u]*(a[v]^a[u]));
        }
}
// void brute()
// {
//         cin>>n;
//         for(int i=1;i<=n;i++)
//                 cin>>a[i],T[i].clear();
//         for(int i=0;i<n-1;i++)
//         {
//                 int u,v;cin>>u>>v;
//                 T[u].push_back(v);
//                 T[v].push_back(u);
//         }
//         for(int i=1;i<=n;i++)
//         {
//                 memset(dp,0,sizeof(dp));
//                 root=i;
//                 go(i,-1);
//                 gogo(i,-1);
//                 cout<<dp[i]<<" ";
//         }
//         cout<<'\n';
// }
void gogogo(int v, int p)
{
        if(v==1)
                ans[v]=dp[v];
        else
                ans[v]=ans[p]+(n-sub[v])*(a[p]^a[v])-(sub[v]*(a[v]^a[p]));//what is this transition bro?
        for(auto&u:T[v])
        {
                if(u==p)
                        continue;
                gogogo(u,v);
        }
}
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i],T[i].clear();
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;
                T[u].push_back(v);
                T[v].push_back(u);
        }
        memset(dp,0,sizeof(dp));
        go(1,-1);
        gogo(1,-1);
        // for(int i=1;i<=n;i++)
        //         cerr<<"i: "<<i<<" DP: "<<dp[i]<<'\n';
        gogogo(1,-1);
        for(int i=1;i<=n;i++)
                cout<<ans[i]<<" \n"[i==n];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)
        {
                // brute();
                solve();
        }
        return 0;
}
