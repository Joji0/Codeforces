#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve() 
{
        cin>>n>>s;
        vector<int>stk;
        for(int i=0;i<n;i++)
        {
                if((int)stk.size()>0)
                {
                        if(stk.back()==s[i]) 
                        {
                                stk.pop_back();
                        }
                        else 
                        {
                                stk.push_back(s[i]);
                        }
                }
                else 
                {
                        stk.push_back(s[i]);
                }
        }
        cout<<(stk.size()==0?"YES\n":"NO\n");
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
