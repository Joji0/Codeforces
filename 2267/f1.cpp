#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,q,x;
void solve()
{
        cin>>n>>q;
        vector<int>a(n),ans;
        for(auto&x:a)
                cin>>x;
        sort(a.begin(),a.end());
        ans.push_back(a.back()-a[0]);
        while(a.back())
        {
                vector<int>nxt;
                for(int i=0;i<n;i++)
                        for(int j=i+1;j<n;j++)
                                nxt.push_back(a[i]^a[j]);
                sort(nxt.begin(),nxt.end());
                for(int i=0;i<n;i++)
                        a[i]=nxt[i];
                sort(a.begin(),a.end());
                ans.push_back(a.back()-a[0]);
        }
        while(q--)
        {
                cin>>x;
                if(x>=(int)ans.size())
                        cout<<"0\n";
                else
                        cout<<ans[x]<<'\n';
        }
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
