#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,l,r;
ll b[100005],ans,p[100005],s[100005];
void solve()
{
        cin>>n;
        for(int i=0;i<=n+1;i++)
                p[i]=s[i]=-1ll<<60;
        for(int i=1;i<=n;i++)
                cin>>b[i],p[i]=max(p[i-1],b[i]+i);
        for(int i=n;i>=1;i--)
                s[i]=max(s[i+1],b[i]-i);
        ans=0;
        for(int i=2;i<n;i++)
                ans=max(ans,b[i]+p[i-1]+s[i+1]);
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
