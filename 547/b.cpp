#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int64_t a[N],dp[N],LMN[N],RMN[N];
void solve()
{
        cin>>n;
        memset(LMN,-1,sizeof(LMN));
        for(int i=0;i<N;i++)RMN[i]=n;
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int>stk;
        for(int i=0;i<n;i++)
        {
                while(!stk.empty()&&a[i]<a[stk.back()])
                {
                        RMN[stk.back()]=i;
                        stk.pop_back();
                }
                stk.push_back(i);
        }
        stk.clear();
        for(int i=n-1;i>=0;i--)
        {
                while(!stk.empty()&&a[i]<=a[stk.back()])
                {
                        LMN[stk.back()]=i;
                        stk.pop_back();
                }
                stk.push_back(i);
        }
        for(int i=0;i<n;i++)
        {
                int64_t range=RMN[i]-LMN[i]-1;
                dp[range]=max(dp[range],a[i]);
        }
        for(int i=n-1;i>0;i--)
        {
                if(dp[i]==0)dp[i]=dp[i+1];
                else dp[i]=max(dp[i],dp[i+1]);
        }
        for(int i=1;i<=n;i++)cout<<dp[i]<<" \n"[i==n];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
