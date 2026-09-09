// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,a[N];
void solve()
{
        cin>>n;
        map<int,int>mp;
        int mx=0,at=0,ans=0;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                mp[a[i]]++;
                ans+=a[i];
                if(mp[a[i]]>mx)
                {
                        mx=mp[a[i]];
                        at=a[i];
                }
        }
        if(mx>n-mx+2)ans-=(mx-(n-mx+2))*at;
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
