#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1000000007;
int n;
ll l,r,dp[200005][3];
void solve()
{
        cin>>n>>l>>r;
        ll a=(r+2)/3-((l-1)+2)/3,aa=(r+1)/3-((l-1)+1)/3,aaa=r/3-(l-1)/3;
        dp[1][1]=a,dp[1][2]=aa,dp[1][0]=aaa;
        // cerr<<"a: "<<a<<" aa: "<<aa<<" aaa: "<<aaa<<'\n';
        for(int i=2;i<=n;i++)
        {
                {
                        dp[i][0]=(dp[i][0]+(dp[i-1][0]*aaa))%mod;
                        dp[i][0]=(dp[i][0]+(dp[i-1][1]*aa))%mod;
                        dp[i][0]=(dp[i][0]+(dp[i-1][2]*a))%mod;
                }
                {
                        dp[i][1]=(dp[i][1]+(dp[i-1][0]*a))%mod;
                        dp[i][1]=(dp[i][1]+(dp[i-1][1]*aaa))%mod;
                        dp[i][1]=(dp[i][1]+(dp[i-1][2]*aa))%mod;
                }
                {
                        dp[i][2]=(dp[i][2]+(dp[i-1][0]*aa))%mod;
                        dp[i][2]=(dp[i][2]+(dp[i-1][1]*a))%mod;
                        dp[i][2]=(dp[i][2]+(dp[i-1][2]*aaa))%mod;
                }
        }
        // for(int i=1;i<=n;i++)
        // {
        //         cerr<<"EVALUATING: "<<i<<'\n';
        //         for(int j=0;j<3;j++)
        //                 cerr<<dp[i][j]<<" \n"[j==2];
        // }
        cout<<dp[n][0]%mod<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
