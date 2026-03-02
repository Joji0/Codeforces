#include <bits/stdc++.h>
#include "ds/segtree/persistent_segtree.hpp"
using namespace std;
int n,k,a[1<<17],q,rt[1<<17];
map<int,deque<int>>mp;
struct M
{
        using value_type=int; 
        static int op(int a, int b)
        {
                return a+b;
        }
        static int e()
        {
                return 0;
        }
};
void solve() 
{
        cin>>n>>k; 
        for(int i=0;i<n;i++)cin>>a[i];
        cin>>q;
        PersistentSegTree<M>seg(n);
        int crt=seg.roots[0];
        for(int i=n-1;i>=0;i--)
        {
                if(!mp.count(a[i])||(int)mp[a[i]].size()<k)
                {
                        mp[a[i]].push_back(i);       
                }
                else 
                {
                        int pos=mp[a[i]].front();
                        mp[a[i]].pop_front();
                        mp[a[i]].push_back(i);
                        crt=seg.update(crt,pos,0);
                }
                crt=seg.update(crt,i,1);
                rt[i]=crt;
        }
        int last=0;
        while(q--)
        {
                int l,r;cin>>l>>r;
                l=(l+last)%n+1,r=(r+last)%n+1;
                if(l>r)swap(l,r);
                last=seg.query(rt[l-1],l-1,r-1);
                cout<<last<<'\n';
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
