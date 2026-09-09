// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=300005,B=400;
int n,p;
int64_t w[N],ans[N];
map<int,vector<array<int64_t,2>>>mp;
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)cin>>w[i];
        cin>>p;
        for(int i=0;i<p;i++)
        {
                int a,b;cin>>a>>b;
                if(b<B)mp[b].push_back({a,i});
                else for(int j=a;j<=n;j+=b)ans[i]+=w[j];
        }
        for(auto&[b,v]:mp)
        {
                vector<int64_t>dp(n+1,0);
                for(int i=n;i>=1;i--)dp[i]=(i+b<=n?dp[i+b]:0)+w[i];
                for(auto&[a,i]:v)
                {
                        ans[i]=dp[a];
                }
        }
        for(int i=0;i<p;i++)cout<<ans[i]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
