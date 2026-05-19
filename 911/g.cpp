#include <bits/stdc++.h>
#include "ds/sqrt_decomp/generic_sqrt.hpp"
#include "block_type/value_replace.hpp"
using namespace std;
int n,q;
vector<int>a;
void solve()
{
        cin>>n;
        a.resize(n);
        for(int i=0;i<n;i++)cin>>a[i];
        GenericSqrt<ValueReplaceBlock<101>>sq(a);
        cin>>q;
        while(q--)
        {
                int l,r,x,y;cin>>l>>r>>x>>y;l--,r--;
                sq.update(l,r,x,y);
        }
        sq.push_all();
        for(int i=0;i<n;i++)cout<<sq.a[i]<<" \n"[i==n-1];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
