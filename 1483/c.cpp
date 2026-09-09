#include <bits/stdc++.h>
#include "acted_monoid/max_add.hpp"
#include "ds/segtree/lazy_segtree.hpp"
using namespace std;
const int N=300005;
int n;
int64_t h[N],b[N],dp[N];
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>h[i];
        for(int i=0;i<n;i++)cin>>b[i];
        vector<int>stk;
        LazySegTree<MaxAdd<int64_t>>seg(vector<int64_t>(n,0));
        for(int i=0;i<n;i++)
        {
                while(!stk.empty()&&h[i]<=h[stk.back()])
                {
                        int bck=stk.back();stk.pop_back();
                        int l=(stk.empty()?0:stk.back()+1),r=bck;
                        seg.update(l,r,b[i]-b[bck]);
                }
                stk.push_back(i);
                seg.update(i,(i?dp[i-1]:0)+b[i]);
                dp[i]=seg.query(0,i);
        }
        cout<<dp[n-1]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
