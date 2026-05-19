#include <bits/stdc++.h>
using namespace std;
int n;
int64_t d,p[1<<17];
void solve()
{
        int64_t ans=0;
        cin>>n>>d;
        for(int i=0;i<n;i++)cin>>p[i];
        for(int i=0;i<n;i++)
        {
                auto itr=upper_bound(p,p+n,p[i]+d)-p;
                int64_t C=itr-i-1;
                if(C>=2)ans+=C*(C-1)/2;
        }
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
