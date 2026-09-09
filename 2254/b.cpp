// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve()
{
        cin>>n>>s;
        int cnt=1,ok=0;
        for(int i=1;i<n;i++)cnt+=(bool)(s[i]!=s[i-1]);
        for(int i=1;i<n-1;i++)
        {
                if(s[i]!=s[i-1]&&s[i-1]==s[i+1])ok=max(ok,2);
                if(s[i]!=s[i-1]&&s[i]!=s[i+1])ok=max(ok,1);
        }
        cout<<cnt-ok<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
