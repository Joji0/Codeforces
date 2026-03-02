#include <bits/stdc++.h>
using namespace std;
int64_t w,h,n;
void solve() 
{
        cin>>w>>h>>n;
        if(w<h)swap(w,h);
        int64_t l=1,r=1LL<<60,ans=0;
        while(l<=r)
        {
                int64_t md=(l+r)>>1,mxw=md/w,mwh=md/h;
                if((__int128)mxw*mwh>=n)
                {
                        ans=md;
                        r=md-1;
                }
                else 
                {
                        l=md+1;
                }
        }
        cout<<ans<<'\n';
}
int main() {
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
