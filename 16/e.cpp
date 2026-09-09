#include <bits/stdc++.h>
using namespace std;
const int N=20;
double a[N][N],dp[1<<N];
int n;
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
        dp[(1<<n)-1]=1.0;
        for(int mask=(1<<n)-1;mask>=0;mask--)
        {
                int alive=__builtin_popcount(mask),pairs=alive*(alive-1)/2;
                for(int i=0;i<n;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                if(((mask>>i)&1)&&((mask>>j)&1))
                                {
                                        dp[mask^(1<<j)]+=dp[mask]*1.0/pairs*a[i][j];
                                }
                        }
                }
        }
        for(int i=0;i<n;i++)cout<<fixed<<setprecision(10)<<dp[1<<i]<<" \n"[i==n-1];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
