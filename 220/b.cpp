#include <bits/stdc++.h>
#include "ds/segtree/segtree.hpp"
#include "monoid/add.hpp"
using namespace std;
int n,m,a[1<<17],ans[1<<17];
vector<array<int,2>>Q[1<<17];
deque<int>pos[1<<17];
void solve()
{
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)
        {
                int l,r;cin>>l>>r;l--,r--;
                Q[r].push_back({l,i});
        }
        for(int i=0;i<n;i++)sort(Q[i].begin(),Q[i].end());
        SegTree<AddMonoid<int64_t>>seg(n);
        for(int r=0;r<n;r++)
        {
                if(a[r]<1<<17)
                {
                        pos[a[r]].push_back(r);
                        int sz=(int)pos[a[r]].size();
                        if(sz>=a[r])
                        {
                                seg.update(pos[a[r]][sz-a[r]],1);
                        }
                        if(sz>=a[r]+1)
                        {
                                seg.update(pos[a[r]][sz-a[r]-1],-1);
                        }
                        if(sz>=a[r]+2)
                        {
                                seg.update(pos[a[r]][sz-a[r]-2],0);
                        }
                }
                for(auto[l,i]:Q[r])
                {
                        ans[i]=seg.query(l,r);
                }
        }
        for(int i=0;i<m;i++)cout<<ans[i]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
