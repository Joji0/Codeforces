#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>T[1<<17];
int64_t s[1<<17],ans;
bool ok=true;
void dfs(int v, int64_t sp)
{
        int64_t mn=1LL<<60;
        if(s[v]==-1)
        {
                bool leaf=true;
                for(int u:T[v])
                {
                        leaf=false;
                        ok&=(s[u]>=sp);
                        mn=min(mn,s[u]);
                }
                if(leaf)return;
                ans+=mn-sp;
                s[v]=mn;
                for(int u:T[v])
                {
                        dfs(u,s[v]);
                }
        }
        else 
        {
                ok&=(s[v]>=sp);
                ans+=s[v]-sp;
                for(int u:T[v])
                {
                        dfs(u,s[v]);
                }
        }
}
void solve() 
{
        cin>>n;
        for(int i=2;i<=n;i++)
        {
                int p;cin>>p;
                T[p].push_back(i);
        }
        for(int i=1;i<=n;i++)cin>>s[i];
        ans=0;
        dfs(1,0);
        if(!ok)cout<<"-1\n";
        else cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
