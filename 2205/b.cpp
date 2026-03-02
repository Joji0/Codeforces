#include <bits/stdc++.h>
using namespace std;
int n;
void solve() 
{
        cin>>n;  
        int ans=1;
        for(int i=2;i*i<=n;i++)
        {
                bool f=true;
                while(n%i==0)
                {
                        if(f)ans*=i,f=false;
                        n/=i;
                }
        }
        if(n>1)ans*=n;
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
