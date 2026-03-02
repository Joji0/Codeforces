#include <bits/stdc++.h>
using namespace std;
int64_t n,a[1<<17];
void solve() 
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int64_t ans=-(a[0]+a[1]);
        reverse(a,a+n);
        ans+=a[0]+a[1];
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
