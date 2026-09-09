#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,prev=1;
vector<int>T[MAXN];
bool vis[MAXN];
void dfs(int v, int par)
{
        cout<<v<<" ";
        for(int nxt:T[v])
        {
                if(nxt==par)continue;
                dfs(nxt,v);
                cout<<v<<" ";
        }
}
void solve()
{
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
                int a,b;cin>>a>>b;
                T[a].push_back(b);
                T[b].push_back(a);
        }
        for(int i=1;i<=n;i++)sort(T[i].begin(),T[i].end());
        dfs(1,-1);
        cout<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
