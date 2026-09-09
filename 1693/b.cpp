#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int64_t l[N],r[N];
void solve()
{
        cin>>n;
        vector<vector<int>>T(n,vector<int>());
        for(int i=1;i<n;i++)
        {
                int p;cin>>p;p--;
                T[p].push_back(i);
        }
        for(int i=0;i<n;i++)cin>>l[i]>>r[i];
        int ans=0;
        auto dfs=[&](auto& dfs, int u)->int64_t
        {
                int64_t sum=0;
                for(int nxt:T[u])
                {
                        sum+=dfs(dfs,nxt);
                }
                if(sum<l[u])
                {
                        ans++;
                        return r[u];
                }
                else return min(sum,r[u]);
        };
        dfs(dfs,0);
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
