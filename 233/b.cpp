// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int64_t n;
int go(int64_t x)
{
        int ret=0;
        while(x>0)
        {
                ret+=x%10;
                x/=10;
        }
        return ret;
}
void solve()
{
        cin>>n;
        int64_t ans=-1;
        for(int64_t s=0;s<85;s++)
        {
                int64_t isq=round(sqrtl(s*s+4*n));
                if(isq*isq!=s*s+4*n)continue;
                int64_t x1=(-s+isq)/2,x2=(-s-isq)/2;
                if(x1>=0&&x1*x1+s*x1-n==0&&go(x1)==s)
                {
                        ans=(ans==-1?x1:min(ans,x1));
                }
                if(x2>=0&&x2*x2+s*x2-n==0&&go(x2)==s)
                {
                        ans=(ans==-1?x2:min(ans,x2));
                }
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
