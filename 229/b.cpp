#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<array<int64_t,2>>G[1<<17];
vector<int64_t>p[1<<17],df[1<<17];
void solve() 
{
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
                int u,v;
                int64_t w;
                cin>>u>>v>>w;u--,v--;
                G[u].push_back({v,w});
                G[v].push_back({u,w});
        }
        for(int i=0;i<n;i++)
        {
                int k;cin>>k;
                for(int j=0;j<k;j++)
                {
                        int t;cin>>t;
                        p[i].push_back(t);
                        df[i].push_back(t-j);
                }
        }
        vector<int64_t>d(n,1LL<<60);
        priority_queue<array<int64_t,2>,vector<array<int64_t,2>>,greater<array<int64_t,2>>>pq;
        d[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
                auto[dist,v]=pq.top();pq.pop();
                if(d[v]!=dist)continue;
                int64_t got=-1;
                auto it=lower_bound(p[v].begin(),p[v].end(),dist);
                if(it==p[v].end()||*it!=dist)got=dist;
                else
                {
                        int64_t nw=dist-(it-p[v].begin());
                        auto it2=upper_bound(df[v].begin(),df[v].end(),nw);
                        got=p[v][it2-df[v].begin()-1]+1;
                }
                for(auto[nxt,w]:G[v])
                {
                        int64_t nd=w+got;
                        if(d[nxt]>nd)
                        {
                                d[nxt]=nd;
                                pq.push({d[nxt],nxt});
                        }
                }
        }
        cout<<(d[n-1]==1LL<<60?-1:d[n-1])<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
