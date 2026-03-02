#include <bits/stdc++.h>
using namespace std;
int n;
int64_t ans,ll,rr,a[1<<20],base;
void solve() 
{
        ans=-1LL<<60,base=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                base+=a[i]*(i&1?1:-1);
        }
        ll=1LL<<60,rr=-1LL<<60;
        for(int i=1;i<=n;i++)
        {
                if(i&1)
                {
                        ll=min(ll,2*a[i]+i);
                }
                else
                {
                        rr=max(rr,2*a[i]+i);
                }
        }
        ans=max(ans,base+rr-ll);
        ll=-1LL<<60,rr=1LL<<60;
        for(int i=1;i<=n;i++)
        {
                if(i&1)
                {
                        rr=min(rr,2*a[i]-i);
                }
                else
                {
                        ll=max(ll,2*a[i]-i);
                }
        }
        ans=max(ans,base+ll-rr);
        ans=max(ans,base+n-1-(n%2==0));
        cout<<max(ans,base)<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
