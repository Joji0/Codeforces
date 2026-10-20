#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define inf 0x3f3f3f3f
int p[200005],s[200005],n,ans;
string b;
void solve()
{
        ans=inf;
        cin>>n>>b;
        for(int i=0;i<=n+2;i++)
                p[i]=0,s[i]=0;
        b='#'+b;
        for(int i=1;i<=n;i++)
                p[i]=p[i-1]+bool(b[i]=='1');
        for(int i=n;i>=1;i--)
                s[i]=s[i+1]+bool(b[i]=='0');
        if(b[1]=='1')
        {
                cout<<s[1]<<'\n';
                return;
        }
        for(int i=1;i<=n;i++)
                ans=min(ans,p[i]+s[i+1]);
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
