#include <bits/stdc++.h>
using namespace std;
#define ld long double
ld a,b;
const ld e=exp(1.0);
void solve()
{
        cin>>a>>b;
        ld l=0,r=1e9,ans=-1;
        for(int i=0;i<100;i++)
        {
                ld md=(l+r)/2.0;
                if(pow(e,-a*md)+pow(e,-b*md)>1)
                {
                        l=md+0.1;
                }
                else
                {
                        r=md-0.1;
                        ans=md;
                }
        }
        assert(ans!=-1);
        cout<<fixed<<setprecision(12)<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
