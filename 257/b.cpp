// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve()
{
        cin>>n>>m;
        int x=(m+n)/2,df=(max(n,m)-min(n,m)+1)/2;
        int a=x+df,b=m+n-a;
        if(a>b)swap(a,b);
        b--;
        if(a>b)swap(a,b);
        if(n!=m)cout<<b<<" "<<a<<'\n';
        else cout<<a<<" "<<b<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
