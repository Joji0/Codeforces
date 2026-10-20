#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
pair<string,string>p[105];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>p[i].first>>p[i].second;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
                int ok=1;
                for(int j=1;j<i;j++)
                        if(p[i]==p[j])
                                ok=0;
                if(ok)
                        ans++;
        }
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
