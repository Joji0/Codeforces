#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a,b;
void solve()
{
        cin>>n>>a>>b;
        cout<<max((n-b)-a-2,a-(n-b))<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
