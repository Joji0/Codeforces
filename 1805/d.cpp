#include <bits/stdc++.h>
using namespace std;
int n, d[1<<17],dd[1<<17],mxx[1<<17],ans[1<<17];
vector<int>T[1<<17];
void dfs(int v, int p)
{
        for(int nxt:T[v])
        {
                if(nxt==p)continue;
                d[nxt]=d[v]+1;
                dfs(nxt,v);
        }
}
void dfs2(int v, int p)
{
        for(int nxt:T[v])
        {
                if(nxt==p)continue;
                dd[nxt]=dd[v]+1;
                dfs2(nxt,v);
        }
}
void solve() 
{
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;u--,v--;
                T[u].push_back(v),T[v].push_back(u);
        }
        dfs(0,-1);
        int mx=max_element(d,d+n)-d;
        for(int i=0;i<n;i++)d[i]=0;
        dfs(mx,-1);
        mx=max_element(d,d+n)-d;
        dfs2(mx,-1);
        for(int i=0;i<n;i++)
        {
                mxx[i]=max(d[i],dd[i]);
        }
        sort(mxx,mxx+n);
        int ptr=0;
        ans[1]=1;
        for(int i=2;i<=n;i++)
        {
                int cnt=0;
                while(ptr<n&&mxx[ptr]<i){cnt++,ptr++;}
                ans[i]=min(ans[i-1]+cnt,n);
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
}
int main() {
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
