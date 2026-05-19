#include <bits/stdc++.h>
using namespace std;
int64_t n,c,d,a[1<<20];
void solve() 
{
        cin>>n>>c>>d;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int64_t l=1,r=1LL<<60,ans=-1;
        while(l<=r)
        {
                int64_t md=(l+r)>>1LL,sum=0,D=d;
                for(int i=0;i<n;i++)
                {
                        sum+=a[i]*min(((d+md-1)/md),D);
                        D-=(d+md-1)/md;
                        if(sum>=c||D<=0)break;
                }
                if(sum>=c)
                {
                        ans=md;
                        l=md+1;
                }
                else 
                {
                        r=md-1;
                }
        }
        if(ans==-1)cout<<"Impossible\n";
        else if(ans>=1LL<<60)cout<<"Infinity\n";
        else cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
