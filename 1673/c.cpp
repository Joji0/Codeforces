#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
const int MAXN=40067;
using Mint=ModInt<1000000007>;
Mint dp[MAXN];
vector<int>pal;
bool ok(int x)
{
        string s=to_string(x);
        string r=s;
        reverse(r.begin(),r.end());
        return r==s;
}
void precompute()
{
        for(int i=1;i<MAXN;i++)if(ok(i))pal.push_back(i);
        int sz=(int)pal.size();
        dp[0]=1;
        for(int i=0;i<sz;i++)
        {
                for(int j=0;j<MAXN;j++)
                {
                        if(j-pal[i]>=0)dp[j]+=dp[j-pal[i]];
                }
        }
}
void solve()
{
        int n;cin>>n;cout<<dp[n]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        precompute();
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
