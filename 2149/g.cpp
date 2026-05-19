#include <bits/stdc++.h>
#include "ds/segtree/segtree.hpp"
#include "monoid/misra_gries.hpp"
using namespace std;
int n,q;
map<int,int>mp;
void solve()
{
        cin>>n>>q;
        vector<int>a(n);
        mp.clear();
        int id=0;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                if(!mp.contains(a[i]))
                {
                        mp[a[i]]=id++;
                }
        }
        vector<vector<int>>pos(id+5);
        vector<MisraGriesMonoid<2>::Node>convA(n);
        for(int i=0;i<n;i++)
        {
                pos[mp[a[i]]].push_back(i);
                convA[i]=MisraGriesMonoid<2>::Node(a[i]);
        }
        SegTree<MisraGriesMonoid<2>>seg(convA);
        while(q--)
        {
                int l,r;cin>>l>>r;
                l--,r--;
                const int BOUND=(r-l+1)/3;
                MisraGriesMonoid<2>::Node res=seg.query(l,r);
                vector<int>filter;
                for(int i=0;i<2;i++)
                {
                        if(res.c[i]==0)continue;
                        const auto &ps=pos[mp[res.c[i]]];
                        auto itr=upper_bound(ps.begin(),ps.end(),r),itl=lower_bound(ps.begin(),ps.end(),l);
                        int v=itr-itl;
                        if(v>BOUND)filter.push_back(res.c[i]);
                }
                assert((int)filter.size()<=2);
                sort(filter.begin(),filter.end());
                filter.erase(unique(filter.begin(),filter.end()),filter.end());
                if(filter.empty())
                {
                        cout<<"-1\n";
                }
                else
                {
                        for(int x:filter)cout<<x<<" ";
                        cout<<'\n';
                }
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
