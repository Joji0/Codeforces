#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
        set<int>ans,st;
        cin>>n;
        for(int i=0;i<n;i++)
        {
                set<int>nst;
                int a;cin>>a;
                nst.insert(a);
                for(auto&x:st)nst.insert(a|x);
                st=nst;
                for(auto&x:st)ans.insert(x);
        }
        cout<<(int)ans.size()<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
