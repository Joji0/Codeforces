#include <bits/stdc++.h>
using namespace std;
int n;
string s[2];
int64_t dp[1<<20];
void solve()
{
        cin>>n>>s[0]>>s[1];
        for(int i=0;i<=n;i++)dp[i]=1LL<<60;
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
                dp[i+1]=min(dp[i+1],dp[i]+(s[0][i]!=s[1][i]));
                if(i+1<n)dp[i+2]=min(dp[i+2],dp[i]+(s[0][i]!=s[0][i+1])+(s[1][i]!=s[1][i+1]));
        }
        cout<<dp[n]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
