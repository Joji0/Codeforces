#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,a[200005],b[200005],ans=0;
void solve() 
{
        ans=0;
        cin>>n>>m>>x>>y;
        for(int i=0;i<n;i++){cin>>a[i];if(a[i]<=y)ans++;}
        for(int i=0;i<m;i++){cin>>b[i];if(b[i]<=x)ans++;}
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int t=1;
        cin >> t;
        while(t--)solve();
        return 0;
}
