#include <bits/stdc++.h>
using namespace std;
int g[1<<20],dp[1<<20][10],Q,l,r,k,ret;
int f(int n)
{
        string s = to_string(n);
        ret=1;
        for(char ch:s)if(ch!='0')ret*=(ch-'0');
        return ret;
}
void solve() 
{
        for(int i=1;i<1<<20;i++)
        {
                if(i<10)g[i]=i;
                else g[i]=g[f(i)];
        }
        for(int i=1;i<1<<20;i++)
        {
                for(int j=1;j<=9;j++)
                {
                        dp[i][j]=dp[i-1][j]+(g[i]==j);
                }
        }
        cin>>Q;
        while(Q--)
        {
                cin>>l>>r>>k;
                cout<<dp[r][k]-dp[l-1][k]<<'\n';
        }
}
int main() 
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int t=1;
        // cin >> t;
        while(t--)solve();
        return 0;
}
