// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=100005,B=316;
int n,q,a[N],dp[B][N];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<B;i++)
        {
                for(int j=n;j>=1;j--)
                {
                        int nxt=i+a[j]+j;
                        if(nxt>n)dp[i][j]=1;
                        else dp[i][j]=dp[i][nxt]+1;
                }
        }
        cin>>q;
        while(q--)
        {
                int p,k;cin>>p>>k;
                if(k<B)cout<<dp[k][p]<<'\n';
                else
                {
                        int ans=0;
                        for(int i=p;i<=n;)
                        {
                                ans++;
                                i+=a[i]+k;
                        }
                        cout<<ans<<'\n';
                }
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
