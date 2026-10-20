#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[100005],p[100005],s[100005];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i];
        for(int i=1;i<=n;i++)
                p[i]=max(p[i-1],a[i]);
        for(int i=n;i>=1;i--)
                s[i]=max(s[i+1],a[i]);
        for(int i=1;i<=n;i++)
                cout<<max(p[i],s[n-i+1])<<" \n"[i==n];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
