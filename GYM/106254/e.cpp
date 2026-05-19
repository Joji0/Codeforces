#include <bits/stdc++.h>
#include "ds/segtree/segtree.hpp"
#include "monoid/min.hpp"
using namespace std;
int c,q;
void solve()
{
        cin>>c>>q;
        vector<int>T(c);
        for(int i=0;i<c;i++)cin>>T[i];
        SegTree<MinMonoid<int>>seg(T);
        while(q--)
        {
                string t;int l,r;cin>>t>>l>>r;
                if(t=="QUERY")
                {
                        l--,r--;
                        cout<<seg.query(l,r)<<'\n';
                }
                else
                {
                        l--;
                        if(r<T[l])
                        {
                                T[l]=r;
                                seg.update(l,r);
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
