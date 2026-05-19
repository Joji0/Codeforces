#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
using Mint=ModInt<1000000007>;
const set<char>vows={'a','i','u','e','o','y'};
int n;
string s;
Mint dp[1<<11][3];
void solve()
{
        cin>>n>>s;
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
                if(!vows.count(s[i-1]))
                {
                        dp[i][0]=dp[i-1][0]+dp[i-1][2];
                        dp[i][1]=0;
                        dp[i][2]=dp[i-1][1]+dp[i-1][2];
                }
                else
                {
                        dp[i][0]=0;
                        dp[i][1]=dp[i-1][0]+dp[i-1][1];
                        dp[i][2]=0;
                }
        }
        cout<<dp[n][2]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
