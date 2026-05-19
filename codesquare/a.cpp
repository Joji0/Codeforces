#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
                int x;cin>>x;
                ans+=(x!=i);
        }
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
