#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[200005],b[200067];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i];
        for(int i=1;i<=n-4;i++)
                b[i]=a[i]+a[i+2]-a[i+4];
        map<ll,ll>mp;
        ll ans=0;
        for(int i=1;i<=n-4;i++)
        {
                ans+=mp[b[i]];
                mp[b[i]]++;
                if(i+2<=n-4)
                        ans-=bool(b[i]==b[i+2]);
                if(i+4<=n-4)
                        ans-=bool(b[i]==b[i+4]);
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
