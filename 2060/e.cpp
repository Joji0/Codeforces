#include <bits/stdc++.h>
#include "ds/unionfind/unionfind.hpp"
using namespace std;
int n,ma,mb;
struct Edge
{
        int u,v;
};
void solve()
{
        cin>>n>>ma>>mb;
        UnionFind ufa(n),ufb(n);
        vector<Edge>ea;
        for(int i=0;i<ma;i++)
        {
                int u,v;cin>>u>>v;u--,v--;
                ea.push_back({u,v});
        }
        for(int i=0;i<mb;i++)
        {
                int u,v;cin>>u>>v;u--,v--;
                ufb.join(u,v);
        }
        int ans=0;
        for(auto[u,v]:ea)
        {
                if(!ufb.same(u,v))ans++;
                else ufa.join(u,v);
        }
        ans+=ufa.num_comps-ufb.num_comps;
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
