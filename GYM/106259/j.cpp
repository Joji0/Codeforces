#include <bits/stdc++.h>
#include "mod/modint.hpp"
#include "monoid/add.hpp"
#include "ds/segtree/segtree.hpp"
using namespace std;
using Mint=ModInt<998244353>;
Mint f[1<<20];
int n,q;
set<int>st;
void precompute()
{
        f[0]=1;
        for(int i=1;i<1<<20;i++)
        {
                f[i]=i*f[i-1];
        }
}
void solve()
{
        st.clear();
        cin>>n>>q;
        vector<Mint>a(n);
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                st.insert(i);
        }
        SegTree<AddMonoid<Mint>>seg(a);
        while(q--)
        {
                int t,l,r;cin>>t>>l>>r;
                l--,r--;
                if(t==1)
                {
                        vector<int>del;
                        for(auto&x:st)
                        {
                                if(x>=l&&x<=r)del.push_back(x);
                                else if(x>r)break;
                        }
                        for(auto&x:del)
                        {
                                st.erase(x);
                                seg.update(x,f[a[x].value()]);
                        }
                }
                else
                {
                        cout<<seg.query(l,r)<<'\n';
                }
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        precompute();
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
