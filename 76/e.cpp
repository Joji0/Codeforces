#include <bits/stdc++.h>
using namespace std;
int n;
int64_t x[1<<17],y[1<<17],sfx[1<<17],sfy[1<<17];
void solve() 
{
        cin>>n;
        int64_t ans=0;
        for(int i=0;i<n;i++)cin>>x[i]>>y[i];
        sort(x,x+n);
        sort(y,y+n);
        for(int i=n-1;i>=0;i--)sfx[i]=sfx[i+1]+x[i];
        for(int i=n-1;i>=0;i--)sfy[i]=sfy[i+1]+y[i];
        for(int i=0;i<n;i++)
        {
                ans+=(n-1)*x[i]*x[i]-2*x[i]*sfx[i+1]+(n-1)*y[i]*y[i]-2*y[i]*sfy[i+1];
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
