#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int64_t LMX[N],RMX[N],LMN[N],RMN[N],a[N],ans=0;
int n;
void solve()
{
        cin>>n;
        memset(LMX,-1,sizeof(LMX));
        memset(LMN,-1,sizeof(LMN));
        for(int i=0;i<N;i++)RMX[i]=RMN[i]=n;
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int>stk;
        for(int i=0;i<n;i++)
        {
                while(!stk.empty()&&a[i]>a[stk.back()])
                {
                        int b=stk.back();stk.pop_back();
                        RMX[b]=i;
                }
                stk.push_back(i);
        }
        stk.clear();
        for(int i=n-1;i>=0;i--)
        {
                while(!stk.empty()&&a[i]>=a[stk.back()])
                {
                        int b=stk.back();stk.pop_back();
                        LMX[b]=i;
                }
                stk.push_back(i);
        }
        stk.clear();
        for(int i=0;i<n;i++)
        {
                while(!stk.empty()&&a[i]<a[stk.back()])
                {
                        int b=stk.back();stk.pop_back();
                        RMN[b]=i;
                }
                stk.push_back(i);
        }
        stk.clear();
        for(int i=n-1;i>=0;i--)
        {
                while(!stk.empty()&&a[i]<=a[stk.back()])
                {
                        int b=stk.back();stk.pop_back();
                        LMN[b]=i;
                }
                stk.push_back(i);
        }
        for(int i=0;i<n;i++)
        {
                ans+=int64_t(i-LMX[i])*(RMX[i]-i)*a[i];
                ans-=int64_t(i-LMN[i])*(RMN[i]-i)*a[i];
        }
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
