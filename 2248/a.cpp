// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
        cin>>s;
        string ans;
        int ok1=1,ok2=1;
        for(int i=0;i<(int)s.size();i++)
        {
                if(s[i]=='0'&&ok1)ok1=0;
                else if(s[i]=='1'&&ok2)ok2=0;
                else ans+=s[i];
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
