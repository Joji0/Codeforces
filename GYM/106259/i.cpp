#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>stk;
void solve()
{
        stk.clear();
        cin>>n;
        for(int i=0;i<n;i++)
        {
                int nw;cin>>nw;
                while((int)stk.size()>1&&stk[stk.size()-2]<stk.back()&&stk.back()>nw)stk.pop_back();
                stk.push_back(nw);
        }
        cout<<((int)stk.size()==2?"YES\n":"NO\n");
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
