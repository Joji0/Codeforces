#include <bits/stdc++.h>
using namespace std;
int n,vis[1<<20];
vector<int>T[1<<20];
map<int,int>mp;
void solve()
{
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
                int x,y;cin>>x>>y;x--,y--;
                T[x].push_back(y),T[y].push_back(x);
        }
        vector<int>a;
        for(int i=0;i<n;i++)
        {
                int x;cin>>x;x--;
                mp[x]=i;
                a.push_back(x);
        }
        for(int i=0;i<n;i++)
        {
                auto &adj=T[i];
                sort(adj.begin(),adj.end(),[&](const auto&x, const auto&y){return mp[x]<mp[y];});
        }
        vector<int>got={0};
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty())
        {
                int f=q.front();q.pop();
                for(auto&x:T[f])
                {
                        if(!vis[x])
                        {
                                q.push(x);
                                got.push_back(x);
                                vis[x]=true;
                        }
                }
        }
        cout<<(a==got?"YES\n":"NO\n");
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
