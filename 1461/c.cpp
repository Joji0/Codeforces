#include <bits/stdc++.h>
using namespace std;
const int N=100005;
#define ld long double
int n,m,a[N];
void solve()
{
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        ld f=1;
        int i=n;
        while(i>0&&a[i]==i)i--;
        while(m--)
        {
                int r;ld p;cin>>r>>p;
                if(r>=i)f*=(1.0-p);
        }
        ld ans=1;
        if(i)ans=1-f;
        cout<<fixed<<setprecision(10)<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
