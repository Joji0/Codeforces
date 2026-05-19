#include <bits/stdc++.h>
using namespace std;
int n,p[1<<20];
void solve() 
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>p[i];
        vector<int>s(n);
        iota(s.begin(),s.end(),0);
        int ans=-1;
        for(int i=0;i<n;i++)
        {
                if(p[i]!=s[i])
                {
                        if(ans==-1)
                        {
                                ans=p[i];
                        }
                        else
                        {
                                ans&=p[i];
                        }
                }
        }
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
