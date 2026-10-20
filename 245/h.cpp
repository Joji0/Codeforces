#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,q;
string s;
bool ok[5005][5005];
ll dp[5005][5005];
void solve()
{
        cin>>s>>q;
        n=s.size();
        s='#'+s;
        for(int i=1;i<=n;i++)
                ok[i][i]=1;
        for(int i=1;i<n;i++)
                ok[i][i+1]=s[i]==s[i+1];
        for(int len=3;len<=n;len++)
                for(int i=1;i+len-1<=n;i++)
                        ok[i][i+len-1]=(s[i]==s[i+len-1])&&(ok[i+1][i+len-1-1]);
        for(int i=1;i<=n;i++)
                dp[i][i]=1;
        for(int len=2;len<=n;len++)
                for(int i=1;i+len-1<=n;i++)
                        dp[i][i+len-1]=dp[i+1][i+len-1]+dp[i][i+len-1-1]-dp[i+1][i+len-1-1]+ok[i][i+len-1];
        while(q--)
        {
                int l,r;cin>>l>>r;
                cout<<dp[l][r]<<'\n';
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
