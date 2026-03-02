#include <bits/stdc++.h>
#include <atcoder/convolution>
using namespace std;
int n;
int64_t x;
vector<int64_t>a,pref,cnt,rcnt;
void solve() 
{
        cin>>n>>x;
        a.resize(n),pref.assign(n+1,0),cnt.assign(n+1,0);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)pref[i]=pref[i-1]+(a[i-1]<x);
        for(int x:pref)cnt[x]++;
        rcnt=cnt;
        reverse(rcnt.begin(),rcnt.end());
        auto g=atcoder::convolution_ll(cnt,rcnt);
        int64_t k0=0;
        for(int i=0;i<=n;i++)k0+=1LL*cnt[i]*(cnt[i]-1)/2;
        cout<<k0<<" ";
        for(int i=1;i<=n;i++)cout<<g[i+n]<<" ";
        cout<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
