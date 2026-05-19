#include <bits/stdc++.h>
using namespace std;
int n,a[1<<20];
int64_t ans[1<<20];
vector<int>T[1<<20];
vector<pair<int,int64_t>> compressor(vector<pair<int,int64_t>>&x)
{
        sort(x.begin(),x.end());
        vector<pair<int,int64_t>>ret;
        for(auto[g,cnt]:x)
        {
                if(!ret.empty()&&ret.back().first==g)
                {
                        ret.back().second+=cnt;
                }
                else
                {
                        ret.push_back({g,cnt});
                }
        }
        return ret;
}
vector<pair<int,int64_t>>dfs(int v, int p)
{
        vector<pair<int,int64_t>>ret;
        ans[a[v]]++;
        ret.push_back({a[v],1});
        for(int u:T[v])
        {
                if(u==p)continue;
                vector<pair<int,int64_t>>nxt=dfs(u,v);
                for(auto[gu,cu]:nxt)
                {
                        for(auto[gv,cv]:ret)
                        {
                                ans[gcd(gu,gv)]+=cu*cv;
                        }
                }
                for(auto[gu,cu]:nxt)
                {
                        ret.push_back({gcd(gu,a[v]),cu});
                }
                ret=compressor(ret);
        }
        return ret;
}
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;u--,v--;
                T[u].push_back(v),T[v].push_back(u);
        }
        dfs(0,-1);
        for(int i=1;i<1<<20;i++)
        {
                if(ans[i]>0)
                {
                        cout<<i<<" "<<ans[i]<<'\n';
                }
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
