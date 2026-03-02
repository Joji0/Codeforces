#include <bits/stdc++.h>
using namespace std;
int n,s,a[200005],pref[200005],ans;
void solve() 
{
        ans=1<<30;
        cin>>n>>s;
        for(int i=0;i<n;i++)cin>>a[i];
        pref[0]=a[0];for(int i=1;i<n;i++)pref[i]=pref[i-1]+a[i];
        for(int i=0;i<n;i++)
        {
                int rg=1<<30,l=i,r=n-1;
                while(l<=r)
                {
                        int md=(l+r)>>1;
                        if(pref[md]-(i?pref[i-1]:0)<=s)
                        {
                                if(pref[md]-(i?pref[i-1]:0)==s)rg=md;
                                l=md+1;
                        }
                        else
                        {
                                r=md-1;
                        }
                }
                if(rg!=1<<30)ans=min(ans,n-(rg-i)-1);
        }
        cout<<(ans==1<<30?-1:ans)<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
