#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,ans=0;
pair<string,string>p[105];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>p[i].first>>p[i].second;
        for(int i=1;i<=n;i++)
        {
                int ok=1;
                for(int j=1;j<i;j++)
                        if(p[j]==p[i])
                        {
                                ok=0;
                                break;
                        }
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
