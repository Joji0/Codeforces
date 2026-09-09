#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,q,a[N],dp[N][N],f[N][N];
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)f[0][i]=a[i];
        for(int i=1;i<n;i++)for(int j=0;j<n-i;j++)f[i][j]=f[i-1][j]^f[i-1][j+1];
        for(int i=n;i>=1;i--)for(int j=i;j<=n;j++)dp[i][j]=max({dp[i][j],f[j-i][i-1],dp[i+1][j],dp[i][j-1]});
        cin>>q;
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
