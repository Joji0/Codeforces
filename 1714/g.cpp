#include <bits/stdc++.h>
using namespace std;
int n;
int64_t ans[1<<20],pa[1<<20];
vector<array<int64_t,3>>T[1<<20];
vector<int64_t>dp;
void dfs1(int v)
{
        for(auto[u,a,b]:T[v])
        {
                pa[u]=pa[v]+a;
                dfs1(u);
        }
}
void dfs2(int v)
{
        for(auto[u,a,b]:T[v])
        {
                if(dp.empty())
                {
                        dp.push_back(b);
                }
                else 
                {
                        dp.push_back(dp.back()+b);
                }
                ans[u]=upper_bound(dp.begin(),dp.end(),pa[u])-dp.begin();
                dfs2(u);
                dp.pop_back();
        }
}
void solve() 
{
        dp.clear();
        cin>>n;
        for(int i=1;i<=n;i++)T[i].clear(),ans[i]=0,pa[i]=0;
        for(int i=2;i<=n;i++)
        {
                int p,a,b;cin>>p>>a>>b;
                T[p].push_back({i,a,b});
        }
        dfs1(1);
        dfs2(1);
        for(int i=2;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
