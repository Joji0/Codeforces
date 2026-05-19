#include <bits/stdc++.h>
using namespace std;
int n;
int mat[505][505],mymat[505][505];
bool vis[505],viss[505];
vector<int>T[505];
vector<array<int,2>>edges;
bool simulate()
{
        for(auto[u,v]:edges)
        {
                T[u].push_back(v);
        }
        for(int i=1;i<=n;i++)
        {
                queue<int>q;
                for(int j=1;j<=n;j++)vis[j]=false;
                q.push(i);
                mymat[i][i]=1;
                vis[i]=true;
                while(!q.empty())
                {
                        int f=q.front();q.pop();
                        for(int u:T[f])
                        {
                                if(!vis[u])
                                {
                                        vis[u]=true;
                                        q.push(u);
                                        mymat[i][u]=1;
                                }
                        }
                }
        }
        bool ok=true;
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++)ok&=(mat[i][j]==mymat[i][j]);
        }
        if(!ok)return false;
        vector<vector<int>>uT(n+1);
        for(auto[u,v]:edges)
        {
                uT[u].push_back(v),uT[v].push_back(u);
        }
        queue<int>qq;
        for(int i=1;i<=n;i++)viss[i]=false;
        qq.push(1);
        viss[1]=true;
        int cnt=0;
        while(!qq.empty())
        {
                int f=qq.front();qq.pop();
                cnt++;
                for(int u:uT[f])
                {
                        if(!viss[u])
                        {
                                viss[u]=true;
                                qq.push(u);
                        }
                }
        }
        return cnt==n;
}
void solve() 
{
        edges.clear();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                string s;cin>>s;
                for(int j=0;j<n;j++)
                {
                        mat[i][j+1]=s[j]-'0';
                        mymat[i][j+1]=0;
                }
                vis[i]=false;
                T[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++)
                {
                        if(i!=j&&mat[i][j]==1)
                        {
                                bool direct=true;
                                for(int k=1;k<=n;k++)
                                {
                                        if(mat[i][k]&&mat[k][j]&&k!=i&&k!=j)direct=false;
                                }
                                if(direct)edges.push_back({i,j});
                        }
                }
        }
        if((int)edges.size()!=n-1)
        {
                cout<<"No\n";
                return;
        }
        if(!simulate())
        {
                cout<<"No\n";
                return;
        }
        cout<<"Yes\n";
        for(auto[u,v]:edges)
        {
                cout<<u<<" "<<v<<'\n';
        }
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
