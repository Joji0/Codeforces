// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,c[N];
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>c[i];
        sort(c,c+n);
        int ans=n;
        for(int i=1;i<=2500;i++)
        {
                for(int j=i;j<=i<<1;j++)
                {
                        int it1=lower_bound(c,c+n,i)-c,it2=upper_bound(c,c+n,j)-c;
                        ans=min(ans,n-(it2-it1));
                }
        }
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
