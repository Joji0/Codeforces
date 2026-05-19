#include <bits/stdc++.h>
using namespace std;
int n,k;
int64_t a[1<<20],pref[1<<20];
void solve()
{
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<k;i++)
        {
                int s,e;cin>>s>>e;s--,e--;
                pref[s]++,pref[e+1]--;
        }
        for(int i=0;i<n;i++)
        {
                pref[i]+=(i?pref[i-1]:0);
                cout<<pref[i]+a[i]<<" \n"[i==n-1];
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
