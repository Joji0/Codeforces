#include <bits/stdc++.h>
using namespace std;
int n,io=0;
int64_t a[200005],ans=0,odd[200005];
void solve() 
{
        ans=0,io=0;
        cin>>n;
        for(int i=0;i<n;i++){cin>>a[i];if(a[i]%2==0)ans+=a[i];else odd[io++]=a[i];}
        sort(odd,odd+io,greater<int64_t>());
        for(int i=0;i<(io+1)/2;i++)ans+=odd[i];
        if(!io)ans=0;
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
