#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,d[10005];
void solve()
{
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;u--,v--;
                d[u]++,d[v]++;
        }
        ll ans=0;
        for(int i=0;i<n;i++)ans+=1ll*d[i]*(d[i]-1)/2;
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
