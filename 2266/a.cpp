#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a,b,c;
void solve()
{
        cin>>n>>a>>b>>c;
        cout<<n-min(a,min(b,c))<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
