#include <bits/stdc++.h>
using namespace std;
int n,L[1<<20],R[1<<20],dp[1<<20];
string s;
void dfs(int v)
{
        if(L[v]==0&&R[v]==0)
        {
                dp[v]=0;
        }
        else if(L[v]&&R[v])
        {
                dfs(L[v]);
                dfs(R[v]);
                dp[v]=min(dp[L[v]]+!(s[v]=='L'),dp[R[v]]+!(s[v]=='R'));
        }
        else if(L[v])
        {
                dfs(L[v]);
                dp[v]=dp[L[v]]+!(s[v]=='L');
        }
        else if(R[v])
        {
                dfs(R[v]);
                dp[v]=dp[R[v]]+!(s[v]=='R');
        }
}
void solve() 
{
        cin>>n>>s;
        s="#"+s;
        for(int i=1;i<=n;i++)
        {
                int l,r;cin>>l>>r;
                L[i]=l,R[i]=r,dp[i]=1<<30;
        }
        dfs(1);
        cout<<dp[1]<<'\n';
}
int main() {
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
