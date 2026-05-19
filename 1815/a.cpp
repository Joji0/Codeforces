#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[1<<20];
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        if(n&1)
        {
                cout<<"YES\n";
                return;
        }
        for(int i=n-2;i>0;i--)
        {
                int64_t d=a[i+1]-a[i];
                a[i]+=d,a[i-1]+=d;
        }
        if(a[0]<=a[1])cout<<"YES\n";
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
