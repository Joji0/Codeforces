// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
        cin>>s;
        vector<char>stk;
        for(int i=0;i<(int)s.size();i++)
        {
                if(!stk.empty()&&stk.back()!=s[i])stk.pop_back();
                else stk.push_back(s[i]);
        }
        for(char c:stk)cout<<c<<"";
        cout<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
