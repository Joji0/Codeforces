#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
using Mint=ModInt<1000000007>;
const int N=100005;
string s;
Mint dp[N];
void solve()
{
        cin>>s;
        memset(dp,0,sizeof(dp));
        dp[0]=(s[0]=='a');
        int n=(int)s.size();
        Mint cnt=(s[0]=='b'),prev=0;
        if(s[0]=='b')prev=dp[0];
        for(int i=1;i<n;i++)
        {
                if(s[i]=='a')
                {
                        dp[i]=dp[i-1]+prev+1;
                }
                else if(s[i]=='b')
                {
                        dp[i]=dp[i-1];
                        prev=dp[i];
                }
                else dp[i]=dp[i-1];
        }
        cout<<dp[n-1]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
