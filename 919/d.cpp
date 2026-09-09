// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,deg[N],ok=1,mx=1,dp[N][26];
set<int>G[N];
string s;
vector<int>topo()
{
        vector<int>ret;
        queue<int>q;
        for(int i=1;i<=n;i++)if(!deg[i])
        {
                q.push(i);
                dp[i][s[i]-'a']=1;
        }
        while(!q.empty())
        {
                int f=q.front();q.pop();
                ret.push_back(f);
                for(int nxt:G[f])
                {
                        if(--deg[nxt]==0)q.push(nxt);
                        for(int i=0;i<26;i++)
                        {
                                dp[nxt][i]=max(dp[nxt][i],dp[f][i]+(bool)(s[nxt]-'a'==i));
                                mx=max(mx,dp[nxt][i]);
                        }
                }
        }
        return ret;
}
void solve()
{
        cin>>n>>m>>s;
        s='#'+s;
        for(int i=0;i<m;i++)
        {
                int u,v;cin>>u>>v;
                if(!G[u].contains(v))deg[v]++;
                G[u].insert(v);
                if(u==v)ok=0;
        }
        if(!ok)
        {
                cout<<"-1\n";
                return;
        }
        vector<int>res=topo();
        cout<<((int)res.size()!=n?-1:mx)<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
