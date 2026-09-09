#include <bits/stdc++.h>
using namespace std;
int64_t s,x;
void solve()
{
        cin>>s>>x;
        if(s-x<0||(s-x)&1||(((s-x)>>1)&x)!=0)cout<<"0\n";
        else cout<<(1LL<<__builtin_popcountll(x))-2*(s==x)<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
