#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,ans[4000005];
bool bad(ll x)
{
        ll rt=round(sqrt(x));
        return rt*rt==x;
}
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                ans[i]=i;
                if(i+1<=n&&bad(2ll*i+1))
                        swap(ans[i],ans[i-1]);
        }
        for(int i=1;i<=n;i++)
                cout<<ans[i]<<" \n"[i==n];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
