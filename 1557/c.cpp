#include <bits/stdc++.h>
#include "mod/modint.hpp"
using namespace std;
using Mint=ModInt<1000000007>;
int64_t n,k;
Mint dp[1<<20];
void solve() 
{
        cin>>n>>k;
        Mint ans=0;
        for(int i=0;i<=k+67;i++)dp[i]=0;
        if(n&1)
        {
                ans=(Mint(2).pow(n-1)+Mint(1)).pow(k);
        }
        else 
        {
                dp[0]=1;
                for(int i=1;i<=k;i++)
                {
                        dp[i]=dp[i-1]*(Mint(2).pow(n-1)-1)+Mint(2).pow(n*(i-1));
                }
                ans+=dp[k];
        }
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
