#include <bits/stdc++.h>
using namespace std;
int n,m,a[1<<8],b[1<<8];
void solve() 
{
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        for(int ans=0;ans<1<<9;ans++)
        {
                bool ok=true;
                for(int i=0;i<n;i++)
                {
                        bool exist=false;
                        for(int j=0;j<m;j++)
                        {
                                exist|=(((a[i]&b[j])|ans)<=ans);
                        }
                        ok&=exist;
                }
                if(ok)
                {
                        cout<<ans<<'\n';
                        return;
                }
        }
        assert(false);
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
