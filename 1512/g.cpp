#include <bits/stdc++.h>
using namespace std;
const int C=10000005;
int64_t sum[C],ask[C];
void solve()
{
        int c;
        cin>>c;
        cout<<ask[c]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        memset(ask,-1,sizeof(ask));
        for(int i=1;i<C;i++)
        {
                for(int j=i;j<C;j+=i)
                {
                        sum[j]+=i;
                }
        }
        for(int i=1;i<C;i++)if(sum[i]<C&&ask[sum[i]]==-1)ask[sum[i]]=i;
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
