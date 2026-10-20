#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define inf 0x3f3f3f3f3f3f3f3f
int n;
ll k;
__int128_t ex[200005];
struct dat
{
        ll a,b,c;
}p[200005];
void solve()
{
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
                cin>>p[i].a>>p[i].b>>p[i].c;
                if(p[i].a<=p[i].b&&p[i].b<=p[i].c)
                {
                        if(p[i].a==p[i].b&&p[i].b==p[i].c)
                                ex[i]=inf;
                        else
                        {
                                ex[i]=(__int128_t)2ll*min(p[i].b-p[i].a+1,p[i].c-p[i].b+1);
                                // cerr<<"i: "<<i<<" ex[i]: "<<ex[i]<<'\n';
                        }
                }
                else
                        ex[i]=0;
        }
        __int128_t l=-inf,r=inf,ans=-inf;
        while(l<=r)
        {
                __int128_t md=(l+r)>>1,tt=0;
                // cerr<<"md: "<<md<<'\n';
                for(int i=1;i<=n;i++)
                {
                        if(p[i].a+p[i].b+p[i].c<md)
                        {
                                tt+=md-((__int128_t)p[i].a+p[i].b+p[i].c)+ex[i];
                                if(tt>k)
                                        break;
                        }
                }
                if(tt<=k)
                {
                        ans=md;
                        l=md+1;
                }
                else
                        r=md-1;
        }
        assert(ans>-inf);
        cout<<(ll)ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
