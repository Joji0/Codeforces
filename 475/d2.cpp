#include <bits/stdc++.h>
using namespace std;
int n,a[1<<17],q;
map<int,int64_t>ans,curr;
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)
        {
                map<int,int64_t>nxt;
                nxt[a[i]]++;
                for(auto[g,cnt]:curr)nxt[gcd(g,a[i])]+=cnt;
                curr=nxt;
                for(auto[g,cnt]:curr)ans[g]+=cnt;
        }
        cin>>q;
        while(q--)
        {
                int x;cin>>x;
                cout<<ans[x]<<'\n';
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
