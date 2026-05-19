#include <bits/stdc++.h>
using namespace std;
int n,k;
int64_t nw(int64_t x, int64_t c)
{
        int64_t div=x/c,md=x%c,up=(x+c-1)/c;
        return (c-md)*div*div+md*up*up;
}
struct dat
{
        int64_t x,c;
        int64_t profit() const
        {
                return nw(x,c)-nw(x,c+1);
        }
};
struct CMP
{
        bool operator()(const dat &a, const dat &b) const
        {
                return a.profit()<b.profit();
        }
};
priority_queue<dat,vector<dat>,CMP>pq;
void solve()
{
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
                int64_t x;cin>>x;
                pq.push({x,1});
        }
        int64_t ans=0;
        for(int i=0;i<k-n;i++)
        {
                auto[x,c]=pq.top();pq.pop();
                pq.push({x,c+1});
        }
        while(!pq.empty())
        {
                int64_t tp=nw(pq.top().x,pq.top().c);pq.pop();
                ans+=tp;
        }
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
