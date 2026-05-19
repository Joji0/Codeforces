#include <bits/stdc++.h>
using namespace std;
int n,k,m,mx=0;
vector<int>G[1<<11],hv;
map<int,set<int>>E;
bool vis[1<<11],bad[1<<11];
void dfs(int v)
{ 
        vis[v]=true;
        hv.push_back(v);
        for(int x:G[v])
        {
                if(!vis[x])dfs(x); 
        }
}
bool chk()
{
        bool ret=true;
        for(int i=0;i<(int)hv.size();i++)
        {
                for(int j=0;j<(int)hv.size();j++)
                {
                        ret&=(!E[hv[i]].count(hv[j]));
                }

        }
        return ret;
}
void solve() 
{
        cin>>n>>k;   
        for(int i=1;i<=n;i++)bad[i]=false;
        for(int i=0;i<k;i++)
        {
                int u,v;cin>>u>>v;
                G[u].push_back(v),G[v].push_back(u);
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
                int u,v;cin>>u>>v;
                E[u].insert(v),E[v].insert(u);
        }
        for(int i=1;i<=n;i++)
        {
                if(bad[i])continue;
                for(int r=1;r<=n;r++)vis[r]=false;
                hv.clear();
                dfs(i);
                if(chk())mx=max(mx,(int)hv.size());
                else 
                {
                        for(int x:hv)bad[x]=true;
                }
        }
        cout<<mx<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
