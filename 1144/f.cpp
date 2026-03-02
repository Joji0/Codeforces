#include <bits/stdc++.h>
using namespace std;
int n,m,d[1<<20],vis[1<<20];
map<array<int,2>,int>mp;
vector<int>G[1<<20];
bool co=false;
string ans;
void dfs1(int v, int p, int dd)
{
        vis[v]=true;
        d[v]=dd;
        for(int nxt:G[v])
        {
                if(nxt==p)continue;
                if(vis[nxt])
                {
                        co=co||((d[v]-d[nxt]+1)&1);
                }
                else 
                {
                        dfs1(nxt,v,dd+1);
                }
        }
}
void dfs2(int v,int p, int prev)
{
        vis[v]=true;
        for(int nxt:G[v])
        {
                if(nxt==p)continue;
                if(prev)
                {
                        if(mp.count({v,nxt}))
                        {
                                ans[mp[{v,nxt}]]='0';
                        }
                }
                else 
                {
                        if(!mp.count({v,nxt}))
                        {
                                ans[mp[{nxt,v}]]='0';
                        }
                }
                if(!vis[nxt])dfs2(nxt,v,prev^1);
        }
}
void solve() 
{
        cin>>n>>m;
        ans.assign(m,'1');
        for(int i=0;i<m;i++)
        {
                int u,v;cin>>u>>v;u--,v--;
                G[u].push_back(v),G[v].push_back(u);
                mp[{u,v}]=i;
        }
        dfs1(0,-1,0);
        if(co)
        {
                cout<<"NO\n";
                return;
        }
        for(int i=0;i<n;i++)vis[i]=false;
        dfs2(0,-1,1);
        cout<<"YES\n";
        cout<<ans<<'\n';
}
int main() {
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
