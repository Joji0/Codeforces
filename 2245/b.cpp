#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int64_t a[N],c;
void solve()
{
        cin>>n>>c;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n,greater<int64_t>());
        int64_t ans=0;
        for(int i=0;i<n/2;i++)ans+=max(a[i]-c,a[i]+a[n-i-1]-2*c);
        if(n&1)ans+=a[n/2]-c;
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
