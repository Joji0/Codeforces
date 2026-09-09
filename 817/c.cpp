// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int64_t n,s;
int64_t go(int64_t x)
{
        int64_t ret=0;
        while(x>0)
        {
                ret+=x%10;
                x/=10;
        }
        return ret;
}
void solve()
{
        cin>>n>>s;
        int64_t l=0,r=n,ans=-1;
        while(l<=r)
        {
                int64_t md=(l+r)>>1;
                if(md-go(md)>=s)
                {
                        ans=md;
                        r=md-1;
                }
                else l=md+1;
        }
        if(ans==-1)cout<<"0\n";
        else cout<<n-ans+1<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
