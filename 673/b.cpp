#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
ll mn=1<<30,mx=-1<<30;
void solve()
{
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
                int u,v;cin>>u>>v;
                if(u>v)swap(u,v);
                mx=max(mx,ll(u));
                mn=min(mn,ll(v));
        }
        cout<<max((!m?ll(n-1):0ll),mn-mx)<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
