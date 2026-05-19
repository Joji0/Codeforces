#include <bits/stdc++.h>
using namespace std;
int n;
void solve() 
{
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
                int64_t a;cin>>a;
                if(a!=i)
                {
                        if(a==1||a==n)
                        {
                                ans=max(ans,1);
                        }
                        else 
                        {
                                ans=max(ans,min(i,n-i));
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
