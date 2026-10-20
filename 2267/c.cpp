#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,x;
ll a[300005],ans;
vector<int>f(int x)
{
        vector<int>ret;
        for(int d=2;d*d<=x;d++)
        {
                while(x%d==0)
                {
                        ret.push_back(d);
                        x/=d;
                }
        }
        if(x>1)
                ret.push_back(x);
        return ret;
}
void solve()
{
        cin>>n>>x;
        for(int i=1;i<=n;i++)
                cin>>a[i];
        auto p=f(x);
        ans=0;
        for(auto&pr:p)
        {
                ll c=0;
                for(int i=1;i<=n;i++)
                        if(a[i]%pr==0)
                                c+=a[i];
                ans=max(ans,c);
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
