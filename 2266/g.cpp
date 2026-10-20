#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll a[200005],b[200005],g[200005],s[200005],ans;
vector<int>T[200005];
void go(int u, int p)
{
        g[u]=0;
        s[u]=0;
        for(int v:T[u])
        {
                if(v==p)continue;
                go(v,u);
                g[u]=gcd(g[u],g[v]%b[v]);
                s[u]+=a[v];
        }
        g[u]=gcd(g[u],s[u]);
        if(g[u])
                g[u]=gcd(g[u],b[u]),
                ans+=a[u]+(b[u]-a[u]-1)/g[u]*g[u];
        else
                ans+=a[u];
}
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i],T[i].clear();
        for(int i=1;i<=n;i++)
                cin>>b[i];
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;
                T[u].push_back(v);
                T[v].push_back(u);
        }
        ans=0;
        go(1,-1);
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
