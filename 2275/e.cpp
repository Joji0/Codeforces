#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[200005],b[200005],p[200005],s[200005],x[200005],y[200005],z[200005];
void solve()
{
        cin>>n;
        for(int i=0;i<=n+2;i++)
                p[i]=s[i]=x[i]=y[i]=z[i]=0;
        for(int i=1;i<=n;i++)
                cin>>a[i];
        for(int i=1;i<=n;i++)
                cin>>b[i];
        if(n==1)
        {
                cout<<(a[1]==b[1]?2:1)<<'\n';
                return;
        }
        for(int i=1;i<=n;i++)
        {
                x[i]=a[i]==b[i]?2:1;
                if(i+1<=n)
                        y[i]=a[i]==b[i+1]?2:1,
                        z[i]=b[i]==a[i+1]?2:1;
                p[i]=p[i-1]+x[i];
        }
        for(int i=n;i>=1;i--)
                s[i]=s[i+1]+y[i];
        ll ans=0,base=x[n];
        for(int i=1;i<n;i++)
                base+=z[i];
        for(int i=1;i<=n;i++)
                ans=max(ans,base+p[i-1]+s[i]);
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
