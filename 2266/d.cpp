#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,ans,c,sz;
ll a[200005],b[200005];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i],b[i]=a[i]-i;
        sort(b+1,b+n+1);
        sz=unique(b+1,b+n+1)-(b+1);
        ans=1,c=1;
        for(int i=1;i<sz;i++)
        {
                if(b[i+1]==b[i]+1)
                {
                        c++;
                        ans=max(ans,c);
                }
                else c=1;
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
