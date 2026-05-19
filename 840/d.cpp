#include <bits/stdc++.h>
#include "ds/segtree/segtree.hpp"
#include "monoid/dynamic_misra_gries.hpp"
using namespace std;
const int MINK=2,MAXK=5;
#define NODE DynamicMisraGriesMonoid<MAXK>::Node
int n,q,a[1<<20];
map<int,int>mp;
void solve()
{
        cin>>n>>q;
        int id=0;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                if(!mp.contains(a[i]))mp[a[i]]=id++;
        }
        vector<vector<int>>pos(id+5);
        for(int i=0;i<n;i++)pos[mp[a[i]]].push_back(i);
        vector<vector<NODE>>pool(MAXK+1,vector<NODE>(n));
        for(int i=MINK;i<=MAXK;i++)
        {
                for(int j=0;j<n;j++)
                {
                        pool[i][j]=NODE(a[j],i);
                }
        }
        vector<SegTree<DynamicMisraGriesMonoid<MAXK>>>vseg(MAXK+1,SegTree<DynamicMisraGriesMonoid<MAXK>>(n));
        for(int i=MINK;i<=MAXK;i++)vseg[i].build(pool[i],1,0,n-1);
        while(q--)
        {
                int l,r,k;cin>>l>>r>>k;l--,r--;
                const auto res=vseg[k].query(l,r);
                set<int>filter;
                for(int i=0;i<k;i++)
                {
                        int nw=res.c[i],BOUND=(r-l+1)/k;
                        if(nw==0)continue;
                        const auto &ps=pos[mp[nw]];
                        int v=upper_bound(ps.begin(),ps.end(),r)-lower_bound(ps.begin(),ps.end(),l);
                        if(v>BOUND)filter.insert(nw);
                }
                if(filter.empty())
                {
                        cout<<"-1\n";
                }
                else
                {
                        cout<<*filter.begin()<<'\n';
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
