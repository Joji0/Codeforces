#include <bits/stdc++.h>
using namespace std;
int n,m;
multiset<int>ms;
void solve()
{
        cin>>n>>m;
        for(int i=0;i<n*m;i++)
        {
                int x;cin>>x;
                ms.insert(x);
        }
        for(int i=0;i<n;i++)
        {
                vector<int>ans;
                for(int j=0;j<m;j++)
                {
                        ans.push_back(*ms.begin());
                        auto it=ms.begin();
                        ms.erase(it);
                }
                for(auto&x:ans)cout<<x<<" ";
                cout<<'\n';
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
