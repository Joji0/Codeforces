// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=100005,B=300;
int n,q;
int64_t a[N];
void solve()
{
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>a[i];
        vector<vector<int64_t>>suff(B,vector<int64_t>(n+B+1,0)),dp(B,vector<int64_t>(n+B+1,0));
        for(int blk=1;blk<B;blk++)
        {
                for(int i=n;i>=1;i--)
                {
                        suff[blk][i]=a[i]+suff[blk][i+blk];
                        dp[blk][i]=a[i]+suff[blk][i+blk]+dp[blk][i+blk];
                }
        }
        while(q--)
        {
                int s,d,k;cin>>s>>d>>k;
                if(d<B)cout<<dp[d][s]-dp[d][s+k*d]-k*suff[d][s+k*d]<<" ";
                else
                {
                        int64_t ans=0;
                        for(int i=1;i<=k;i++)ans+=a[s+(i-1)*d]*i;
                        cout<<ans<<" ";
                }
        }
        cout<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
