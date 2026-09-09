#include <bits/stdc++.h>
#include "monoid/max.hpp"
#include "monoid/min.hpp"
#include "ds/sparse_table/sparse_table.hpp"
using namespace std;
const int N=200005;
int n;
int64_t a[N],LMX[N],RMX[N];
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                LMX[i]=-1;
                RMX[i]=n;
        }
        vector<int64_t>pref(n,0);
        pref[0]=a[0];
        for(int i=1;i<n;i++)pref[i]=pref[i-1]+a[i];
        vector<int>stk;
        for(int i=0;i<n;i++)
        {
                while(!stk.empty()&&a[i]>a[stk.back()])
                {
                        RMX[stk.back()]=i;
                        stk.pop_back();
                }
                stk.push_back(i);
        }
        stk.clear();
        for(int i=n-1;i>=0;i--)
        {
                while(!stk.empty()&&a[i]>=a[stk.back()])
                {
                        LMX[stk.back()]=i;
                        stk.pop_back();
                }
                stk.push_back(i);
        }
        SparseTable<MaxMonoid<int64_t>>mx(pref);
        SparseTable<MinMonoid<int64_t>>mn(pref);
        bool ok=true;
        for(int i=0;i<n;i++)
        {
                int l=LMX[i]+1,r=RMX[i]-1;
                int64_t lhs=a[i],rhs=mx.query(i,r)-(!l?(i?min(int64_t(0),mn.query(0,i-1)):0):mn.query(l-1,i-1));
                // cerr<<i<<" "<<lhs<<" "<<rhs<<"\n";
                ok&=(lhs>=rhs);
        }
        cout<<(ok?"YES":"NO")<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
