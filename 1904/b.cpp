#include <bits/stdc++.h>
using namespace std;
int n;
vector<int64_t> a,idx,ans,pref;
void solve() 
{
        cin>>n;
        a.assign(n,0);
        idx.resize(n);iota(idx.begin(),idx.end(),0);
        ans.assign(n,0);pref.assign(n,0);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(idx.begin(),idx.end(),[&](const int i, const int j){return a[i]<a[j];});
        sort(a.begin(),a.end());
        pref[0]=a[0];for(int i=1;i<n;i++)pref[i]=pref[i-1]+a[i];
        ans[idx[n-1]]=n-1;
        for(int i=n-2;i>=0;i--)
        {
                if(pref[i]>=a[i+1])ans[idx[i]]=ans[idx[i+1]];
                else ans[idx[i]]=i;
        }
        for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i+1==n];
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
