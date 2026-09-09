// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>T[N];
int64_t n,son[N],cnt[N],col[N],sub[N],ans[N];
int64_t big=0,mx=0,sum=0;
void dfs1(int u, int par)
{
        sub[u]=1;
        for(int v:T[u])
        {
                if(v==par)continue;
                dfs1(v,u);
                sub[u]+=sub[v];
                if(sub[v]>sub[son[u]])son[u]=v;
        }
}
void add(int u, int par, int val)
{
        if(val==1)
        {
                cnt[col[u]]++;
                if(cnt[col[u]]>mx)
                {
                        mx=cnt[col[u]];
                        sum=col[u];
                }
                else if(cnt[col[u]]==mx)sum+=col[u];
        }
        else cnt[col[u]]--;
        for(int v:T[u])if(v!=par&&v!=big)add(v,u,val);
}
void dfs2(int u, int par, int keep)
{
        for(int v:T[u])
        {
                if(v==par||v==son[u])continue;
                dfs2(v,u,0);
        }
        if(son[u])
        {
                dfs2(son[u],u,1);
                big=son[u];
        }
        add(u,par,1);
        ans[u]=sum;
        big=0;
        if(!keep)
        {
                add(u,par,-1);
                sum=0;
                mx=0;
        }
}
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)cin>>col[i];
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;
                T[u].push_back(v);
                T[v].push_back(u);
        }
        dfs1(1,-1);
        dfs2(1,-1,1);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
