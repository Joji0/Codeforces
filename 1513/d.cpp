#include <bits/stdc++.h>
#include "ds/unionfind/unionfind.hpp"
using namespace std;
const int N=200005;
int n;
int64_t p,a[N];
array<int64_t,2>b[N];
void solve()
{
        cin>>n>>p;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                b[i]={a[i],i};
        }
        UnionFind dsu(n);
        sort(b,b+n,[](const auto& x, const auto& y){if(x[0]!=y[0])return x[0]<y[0];return x[1]<y[1];});
        int64_t ans=0;
        for(int i=0;i<n&&b[i][0]<p;i++)
        {
                int j=b[i][1]+1;
                while(j<n)
                {
                        if(dsu.same(b[i][1],j)||a[j]%b[i][0]!=0)break;
                        ans+=b[i][0];
                        dsu.join(b[i][1],j);
                        j++;
                }
                j=b[i][1]-1;
                while(j>=0)
                {
                        if(dsu.same(b[i][1],j)||a[j]%b[i][0]!=0)break;
                        ans+=b[i][0];
                        dsu.join(b[i][1],j);
                        j--;
                }
        }
        ans+=p*(dsu.num_comps-1);
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
