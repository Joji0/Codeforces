#include <bits/stdc++.h>
#include "ds/segtree/persistent_segtree.hpp"
using namespace std;
int n,a[1<<17],rt[1<<17],memo[1<<17];
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
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<=n;i++)memo[i]=-1;
        PersistentSegTree<M>seg(n);
        int crt=seg.roots[0];
        for(int i=n-1;i>=0;i--)
        {
                if(memo[a[i]]!=-1)
                {
                        crt=seg.update(crt,memo[a[i]],0);
                }
                crt=seg.update(crt,i,1);
                memo[a[i]]=i;
                rt[i]=crt;
        }
        for(int k=1;k<=n;k++)
        {
                int strt=0,ans=0; 
                while(strt<n)
                {
                        strt=seg.max_right(rt[strt],strt,[&](int x)->bool{return x<=k;});
                        ans++;
                }
                cout<<ans<<" \n"[k==n];
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
