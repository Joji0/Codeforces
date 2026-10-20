#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[200005];
string s;
void solve()
{
        cin>>n>>s;
        for(int i=1;i<=n;i++)
                a[i]=0;
        s='#'+s;
        vector<int>stk;
        for(int i=1;i<=n;i++)
        {
                if(s[i]=='1')
                {
                        stk.push_back(i);
                }
                else if(s[i]=='2')
                {
                        if(!stk.empty())
                        {
                                a[stk.back()]=1;
                                stk.pop_back();
                        }
                        else
                                a[i]=1;
                }
                else
                {
                        a[i]=1;
                }
        }
        vector<int>b;
        for(int i=1;i<=n;i++)
                if(!a[i])
                        b.push_back(i);
        cout<<b.size()<<'\n';
        for(auto&x:b)
                cout<<x<<" ";
        cout<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
