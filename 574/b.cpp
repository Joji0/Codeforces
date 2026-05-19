#include <bits/stdc++.h>
using namespace std;
int n,m;
map<int,set<int>>G;
bool vis[1<<12];
void solve() 
{
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
                int u,v;cin>>u>>v;
                G[u].insert(v),G[v].insert(u);
        }
        int ans=1<<30;
        for(int i=1;i<=n;i++)
        {
                for(int j:G[i])
                {
                        for(int k:G[j])
                        {
                                if(G[i].count(k))
                                {
                                        set<int>nw={i,j,k};
                                        ans=min(ans,(int)G[i].size()+(int)G[j].size()+(int)G[k].size()-6);
                                }
                        }
                }
        }
        cout<<(ans>=(1<<30)?-1:ans)<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
