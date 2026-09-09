// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],pref[N];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                pref[i]=pref[i-1]^a[i];
        }
        int ans=0;
        for(int l=1;l<=n;l++)for(int r=l;r<=n;r++)ans=max(ans,pref[r]^pref[l-1]);
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
