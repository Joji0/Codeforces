#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,ans;
char c;
string s;
void solve()
{
        ans=0;
        cin>>n>>c>>s;
        for(int i=0;i<n/2;i++)
        {
                if(s[i]!=s[n-i-1])
                {
                        if(s[i]!=c&&s[n-i-1]!=c)
                                ans+=2;
                        else
                                ans++;
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
