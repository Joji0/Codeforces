#include <bits/stdc++.h>
using namespace std;
int64_t x,y,xx,yy;
void solve() 
{
        cin>>x>>y>>xx>>yy;
        cout<<(xx-x)*(yy-y)+1<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
