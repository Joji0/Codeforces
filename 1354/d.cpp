#include <bits/stdc++.h>
#include "ds/ordered_multiset.hpp"
using namespace std;
int n,q;
void solve() 
{
        cin>>n>>q;
        OrderedMultiSet<int32_t>os;
        for(int i=0;i<n;i++)
        {
                int32_t x;cin>>x;
                os.insert(x);
        }
        while(q--)
        {
                int32_t k;cin>>k;
                if(k>0)
                {
                        os.insert(k);
                }
                else 
                {
                        k=-k;
                        os.erase_kth(k-1);
                }
        }
        if(os.empty())cout<<"0\n";
        else 
        {
                optional<int32_t> opt=os.erase_kth(0);
                if(opt.has_value())cout<<*opt<<'\n';
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
