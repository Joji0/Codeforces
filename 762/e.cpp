#include <bits/stdc++.h>
#include "ds/ordered_multiset.hpp"
using namespace std;
int n,k;
array<int64_t,3>a[1<<17];
void solve() 
{
        cin>>n>>k;
        vector<OrderedMultiSet<int64_t,less<int64_t>>>os(1<<14,OrderedMultiSet<int64_t,less<int64_t>>());
        for(int i=0;i<n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
        sort(a,a+n,[](const auto&x, const auto&y){return x[1]>y[1];});
        int64_t ans=0;
        for(int i=0;i<n;i++)
        {
                auto[X,R,F]=a[i];
                int64_t cnt=0;
                for(int j=F;j<=F+k;j++)ans+=(int64_t)os[j].count_range(X-R,X+R);
                for(int j=F-1;j>=max(0LL,F-k);j--)ans+=(int64_t)os[j].count_range(X-R,X+R);
                os[F].insert(X);
                ans+=cnt;
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
