#include <bits/stdc++.h>
#include "ds/segtree/segtree.hpp"
#include "monoid/add.hpp"
using namespace std;
int n,k;
int64_t d,a[1<<20];
void solve()
{
        cin>>n>>k>>d;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        SegTree<AddMonoid<int64_t>>dp(n+5);
        dp.update(0,1);
        for(int i=1;i<=n;i++)
        {
                int it=lower_bound(a,a+n,a[i-1]-d)-a;
                if(dp.query(it,i-k)>0&&it<=i-k)
                {
                        dp.update(i,1);
                }
        }
        cout<<(dp.get(n)?"YES\n":"NO\n");
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
