#include <bits/stdc++.h>
#include "ds/treap/implicit_treap.hpp"
using namespace std;
int n,m,q;
struct AM
{
        using S=int64_t;
        using F=int64_t;
        static S op(S a, S b){return a+b;}
        static S e(){return 0;}
        static S mapping(F f, S x){return x;}
        static F composition(F f, F g){return f+g;}
        static F id(){return 0;}
};
void solve() 
{
        cin>>n>>q>>m;
        vector<int64_t>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        ImplicitTreap<AM>treap(a);
        while(q--)
        {
                int t,l,r;cin>>t>>l>>r;
                l--,r--;
                if(t==1)
                {
                        int64_t R=treap.get(r);
                        treap.erase(r),treap.insert(l,R);
                }
                else 
                {
                        treap.reverse(l,r);
                }
        }
        while(m--)
        {
                int x;cin>>x;
                cout<<treap.get(x-1)<<" ";
        }
        cout<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
