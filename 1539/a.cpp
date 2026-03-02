#include <bits/stdc++.h>
using namespace std;
int64_t n,x,t;
void solve() 
{
        cin>>n>>x>>t;
        int64_t to=min(n,t/x);
        cout<<(to-1)*to/2+(n-to)*to<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
