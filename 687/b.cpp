#include <bits/stdc++.h>
#include "nt/sieve.hpp"
using namespace std;
NT::Sieve sieve(1<<20);
int n,k,c[1<<20];
void solve()
{
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>c[i];
        set<int64_t>st;
        for(auto&x:sieve.get_all_divisors(k))st.insert(x);
        for(int i=0;i<n;i++)
        {
                for(auto&x:sieve.get_all_divisors(c[i]))
                {
                        if(st.contains(x))st.erase(x);
                }
        }
        cout<<(st.empty()?"YES\n":"NO\n");
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
