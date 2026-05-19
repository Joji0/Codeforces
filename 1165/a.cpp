#include <bits/stdc++.h>
using namespace std;
int n,x,y;
string s;
void solve() 
{
        cin>>n>>x>>y>>s;
        reverse(s.begin(),s.end());
        int ans=0;
        for(int i=0;i<y;i++)
        {
                if(s[i]=='1')ans++;
        }
        ans+=(s[y]=='0');
        for(int i=y+1;i<x;i++)
        {
                if(s[i]=='1')ans++;
        }
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
