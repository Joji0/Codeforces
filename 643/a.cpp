#include <bits/stdc++.h>
using namespace std;
int n,t[5005],ans[5005],cnt[5005],b=0x3f3f3f,mx=0;
void solve() 
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>t[i];
        for(int i=0;i<n;i++)
        {
                for(int j=i;j<n;j++)
                {
                        cnt[t[j]]++;
                        if(cnt[t[j]]>mx)
                        {
                                mx=cnt[t[j]];
                                b=t[j];
                        }
                        else if(cnt[t[j]]==mx&&t[j]<b)
                        {
                                b=t[j];
                        }
                        ans[b]++;
                }
                memset(cnt,0,4*5005);
                mx=0,b=0x3f3f3f;
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
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
