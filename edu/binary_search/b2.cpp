#include <bits/stdc++.h>
using namespace std;
int n,k;
double a[1<<17];
void solve() 
{
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        double l=0,r=1LL<<60,ans=-1;
        for(int i=0;i<100;i++)
        {
                double md=(l+r)/2;
                int64_t g=0;
                for(int i=0;i<n;i++)
                {
                        g+=(int64_t)(a[i]/md);
                }
                if(g>=k)
                {
                        ans=md;
                        l=md+1;
                }
                else 
                {
                        r=md-1;
                }
        }
        cout<<fixed<<setprecision(12)<<ans<<'\n';
}
int main() {
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
