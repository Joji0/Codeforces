#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll ans;
void solve()
{
        cin>>n;
        priority_queue<ll>pq;
        ans=0;
        for(int i=1;i<=n;i++)
        {
                ll a;cin>>a;
                if(!a&&!pq.empty())
                {
                        ans+=pq.top();
                        pq.pop();
                }
                else
                {
                        pq.push(a);
                }
        }
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
