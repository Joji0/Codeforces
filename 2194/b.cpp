#include <bits/stdc++.h>
using namespace std;
int64_t n,x,y,a[1<<20],k,mx,nw;
void solve() 
{
        k=0;
        cin>>n>>x>>y;
        for(int i=0;i<n;i++)cin>>a[i],k+=a[i]/x;
        mx=0;
        for(int i=0;i<n;i++)
        {
                nw=a[i]/x;
                mx=max(mx,a[i]+(k-nw)*y);
        }
        cout<<mx<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
