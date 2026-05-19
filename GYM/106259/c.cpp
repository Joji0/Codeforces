#include <bits/stdc++.h>
using namespace std;
string s;
vector<char>stk;
void solve()
{
        stk.clear();
        cin>>s;
        for(char c:s)
        {
                if(stk.empty())stk.push_back(c);
                else
                {
                        if(stk.back()==c)stk.pop_back();
                        else stk.push_back(c);
                }
        }
        cout<<(stk.empty()?"YES\n":"NO\n");
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
