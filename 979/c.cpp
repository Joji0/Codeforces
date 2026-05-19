#include <bits/stdc++.h>
using namespace std;
int64_t n,x,y,sub[1<<20];
vector<int>T[1<<20];
bool dfs(int v, int p, int rm)
{
        if(v==rm)return true;
        sub[v]=1;
        int64_t sum=0;
        bool inv=false;
        for(int u:T[v])
        {
                if(u==p)continue;
                if(!dfs(u,v,rm))
                {
                        sub[v]+=sub[u];
                }
                else 
                {
                        inv=true;
                }
        }
        if(inv)return true;
        sub[v]+=sum;
        return false;
}
void solve() 
{
        cin>>n>>x>>y;
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;
                T[u].push_back(v),T[v].push_back(u);
        }
        for(int i=0;i<=n;i++)sub[i]=0;
        dfs(x,-1,y);
        int64_t fx=sub[x];
        for(int i=0;i<=n;i++)sub[i]=0;
        dfs(y,-1,x);
        int64_t fy=sub[y];
        cout<<n*(n-1)-fx*fy<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
