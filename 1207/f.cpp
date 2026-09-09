// 我思う、故に我在り
#include <bits/stdc++.h>
#include "mod/barrett.hpp"
using namespace std;
const int N=500005,B=350;
int q,t;
int64_t a[N],x,y,dp[B][B];
Barrett bar[B];
void solve()
{
        cin>>q;
        for(int i=1;i<B;i++)bar[i]=Barrett(i);
        while(q--)
        {
                cin>>t>>x>>y;
                if(t==1)
                {
                        a[x]+=y;
                        for(int i=1;i<B;i++)dp[i][bar[i].modulo(x)]+=y;
                }
                else
                {
                        if(x<B)cout<<dp[x][y]<<'\n';
                        else
                        {
                                int64_t ans=0;
                                int i=y;
                                while(i<N)
                                {
                                        ans+=a[i];
                                        i+=x;
                                }
                                cout<<ans<<'\n';
                        }
                }
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
