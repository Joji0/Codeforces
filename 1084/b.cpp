#include <bits/stdc++.h>
using namespace std;
int n;
int64_t s,v[1005],tt=0,mn=1<<30;
void solve()
{
        cin>>n>>s;
        for(int i=0;i<n;i++)
        {
                cin>>v[i];
                tt+=v[i];
                mn=min(mn,v[i]);
        }
        if(tt<s)
        {
                cout<<"-1\n";
                return;
        }
        int64_t l=0,r=mn,ans=-1;
        while(l<=r)
        {
                int64_t md=(l+r)>>1,ct=0;
                for(int i=0;i<n;i++)
                {
                        int64_t tk=max((int64_t)0,v[i]-md);
                        ct+=tk;
                        if(ct>=s)break;
                }
                if(ct>=s)
                {
                        ans=md;
                        l=md+1;
                }
                else r=md-1;
        }
        assert(ans!=-1);
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
