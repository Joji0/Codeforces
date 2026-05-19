#include <bits/stdc++.h>
using namespace std;
#define ld long double
int n,c[1<<17],p[1<<17];
void solve() 
{
        cin>>n;
        for(int i=1;i<=n;i++)cin>>c[i]>>p[i];
        ld ans=0;
        for(int i=n;i>=1;i--)
        {
                ans=max(ans,c[i]+ans*(1.0-p[i]/100.0));
        }
        cout<<fixed<<setprecision(12)<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
