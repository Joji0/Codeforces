#include <bits/stdc++.h>
using namespace std;
const int M=55,N=50005;
int m;
int64_t x,c[M],h[M],dp[N];
void solve()
{
        cin>>m>>x;
        for(int i=0;i<m;i++)cin>>c[i]>>h[i];
        for(int i=1;i<N;i++)dp[i]=1LL<<60;
        dp[0]=0;
        for(int i=0;i<m;i++)
        {
                for(int j=N-1;j>=0;j--)
                {
                        if(dp[j]<1LL<<60&&dp[j]+c[i]<=i*x&&j+h[i]<N)dp[j+h[i]]=min(dp[j+h[i]],dp[j]+c[i]);
                }
        }
        for(int i=N-1;i>=0;i--)if(dp[i]<1LL<<60)
        {
                cout<<i<<'\n';
                return;
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
