#include <bits/stdc++.h>
using namespace std;
int n,k,a[1<<20],cnt[1<<20],ans=0;
void solve() 
{
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        int l=0,df=0,ll=-1,rr=-1;
        for(int r=0;r<n;r++)
        {
                while(l<r&&df>k)
                {
                        cnt[a[l]]--;
                        if(cnt[a[l]]==0)df--;
                        l++;
                }
                if(cnt[a[r]]==0)df++;
                cnt[a[r]]++;
                if(r-l+1>ans&&df<=k)
                {
                        ll=l,rr=r,ans=r-l+1;
                }
        }
        assert(ans>0);
        cout<<ll+1<<" "<<rr+1<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
