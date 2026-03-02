#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>G[1<<20],ans,e,o;
bool vis[1<<20];
void solve() 
{
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
                G[i].clear();
                vis[i]=false;
        }
        for(int i=0;i<m;i++)
        {
                int u,v;cin>>u>>v;u--,v--;
                G[u].push_back(v),G[v].push_back(u);
        }
        e.clear(),o.clear();
        queue<array<int,2>>q;
        q.push({0,1});
        vis[0]=true;
        while(!q.empty())
        {
                auto[v,stat]=q.front();q.pop();
                if(stat)
                {
                        e.push_back(v+1);
                }
                else 
                {
                        o.push_back(v+1);
                }
                for(int nxt:G[v])
                {
                        if(vis[nxt])continue;
                        vis[nxt]=true;
                        q.push({nxt,stat^1});
                }
        }
        ans=(e.size()<o.size()?e:o);
        assert((int)ans.size()<=n/2);
        cout<<(int)ans.size()<<'\n';
        for(int an:ans)
        {
                cout<<an<<" ";
        }
        cout<<'\n';
}
int main() {
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
