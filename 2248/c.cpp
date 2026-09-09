// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=400005;
int n;
int64_t a[N],dp[N];
void solve()
{
        cin>>n;
        for(int i=1;i<=2*n;i++)cin>>a[i];
        vector<int>prev(n+1,0);
        for(int i=1;i<=2*n;i++)
        {
                dp[i]=dp[i-1];
                if(prev[a[i]]>0)
                {
                        int64_t l=i-prev[a[i]]+1;
                        dp[i]=max(dp[i],dp[i-l]+l*l-l);
                }
                else prev[a[i]]=i;
        }
        cout<<2*n+dp[2*n]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
