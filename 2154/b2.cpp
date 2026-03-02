#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[1<<20],pref[1<<20];
void solve() 
{
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                pref[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
                pref[i]=max(pref[i-1],a[i]);
        }
        int64_t ans=0;
        for(int i=1;i<=n;i++)
        {
                if(i&1)
                {
                        if(i==1)
                        {
                                if(a[i]>=pref[i+1])
                                {
                                        ans+=a[i]-pref[i+1]+1;
                                }
                        }
                        else if(i<n)
                        {
                                int64_t mn=min(pref[i-1],pref[i+1]);
                                if(a[i]>=mn)
                                {
                                        ans+=a[i]-mn+1;
                                }
                        }
                        else
                        {
                                if(a[i]>=pref[i-1])
                                {
                                        ans+=a[i]-pref[i-1]+1;
                                }
                        }
                }
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
