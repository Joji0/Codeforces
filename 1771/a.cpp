#include <bits/stdc++.h>
using namespace std;
int n,a[1<<17];
void solve()
{
        cin>>n;
        map<int,int64_t>mp;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                mp[a[i]]++;
        }
        sort(a,a+n);
        int64_t ans;
        if(a[0]!=a[n-1])ans=2*mp[a[0]]*mp[a[n-1]];
        else ans=mp[a[0]]*(mp[a[n-1]]-1);
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
