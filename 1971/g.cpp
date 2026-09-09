#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int64_t a[N],ans[N],at[N];
void solve()
{
        map<int64_t,vector<int>>mp;
        map<int64_t,int>ptr;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                int64_t bits=0;
                for(int j=31;j>=2;j--)bits+=((a[i]>>j)&1)*(1<<j);
                mp[bits].push_back(a[i]);
                ptr[bits]=0;
                at[i]=bits;
        }
        for(auto&[_,v]:mp)sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
                int64_t bits=at[i];
                assert(ptr[bits]<(int)mp[bits].size());
                ans[i]=mp[bits][ptr[bits]];
                ptr[bits]++;
        }
        for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
