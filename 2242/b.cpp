#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        int cnt1=0,other=0,i=0,touch=0;
        for(;i<n;i++)
        {
                if(a[i]==1)cnt1++;
                else other++;
                if(cnt1>=other)
                {
                        touch++;
                        i++;
                        break;
                }
        }
        int cnt12=0;
        other=0;
        for(;i<n;i++)
        {
                if(a[i]==1||a[i]==2)cnt12++;
                else other++;
                if(cnt12>=other)
                {
                        touch++;
                        i++;
                        break;
                }
        }
        // cerr<<"TOUCH: "<<touch<<" i: "<<i<<'\n';
        if(touch==2&&i<n)cout<<"YES\n";
        else cout<<"NO\n";
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
