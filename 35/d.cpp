#include <bits/stdc++.h>
using namespace std;
int n,X,c[101],dp[101],tt;
void solve() 
{
        for(int i=0;i<=100;i++)dp[i]=1<<30;
        dp[0]=0;
        cin>>n>>X;
        for(int i=1;i<=n;i++)
        {
                cin>>c[i];
                tt=c[i]*(n-i+1);
                for(int j=i;j>=1;j--)
                {
                        if(dp[j-1]!=1<<30)dp[j]=min(dp[j],dp[j-1]+tt);
                }
        }
        for(int i=n;i>=1;i--)
        {
                if(dp[i]<=X)
                {
                        cout<<i<<'\n';
                        return;
                }
        }
        cout<<"0\n";
}
int main() 
{
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int t=1;
        // cin >> t;
        while(t--)solve();
        return 0;
}
