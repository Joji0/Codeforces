#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,b,c;
void solve()
{
        cin>>a>>b>>c;
        cout<<max({0ll,b-a,a+c-b})<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
