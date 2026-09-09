// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int64_t a[N],b[N];
int n,m;
void solve()
{
        cin>>n>>m;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];
        if(n<m*2)
        {
                cout<<"NO\n";
                return;
        }
        sort(a,a+n),sort(b,b+m);
        for(int i=0;i<m;i++)if(a[i]>b[i]||a[n-m+i]<b[i])
        {
                cout<<"NO\n";
                return;
        }
        cout<<"YES\n";
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
