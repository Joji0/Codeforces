// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int m,q[N],n,a[N],mn=1<<30,ans=0;
void solve()
{
        cin>>m;
        for(int i=0;i<m;i++)
        {
                cin>>q[i];
                mn=min(mn,q[i]);
        }
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n,greater<>());
        for(int i=0;i<n;i++)if(i%(mn+2)<mn)ans+=a[i];
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
