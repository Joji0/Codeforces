// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int a,b,c;
void solve()
{
        cin>>a>>b>>c;
        vector<int>s={a,b,c};
        sort(s.begin(),s.end());
        if(s[0]==s[1]||s[1]==s[2])cout<<"0\n";
        else cout<<max(0,min(s[2]-s[1],s[1]-s[0]))<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
