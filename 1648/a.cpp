#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> a;
map<int,vector<int64_t>>mpx,mpy;
int64_t ans=0;
void solve() 
{
        cin>>n>>m;a.assign(n,vector<int>(m));
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j],mpx[a[i][j]].push_back(i+1),mpy[a[i][j]].push_back(j+1);
        for(auto&[_,v]:mpx)
        {
                sort(v.begin(),v.end());
                for(int i=0;i<(int)v.size();i++)
                {
                        ans+=-1LL*((int)v.size()-i-1)*v[i]+i*v[i];
                }
        }
        for(auto&[_,v]:mpy)
        {
                sort(v.begin(),v.end());
                for(int i=0;i<(int)v.size();i++)
                {
                        ans+=-1LL*((int)v.size()-i-1)*v[i]+i*v[i];
                }
        }
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
