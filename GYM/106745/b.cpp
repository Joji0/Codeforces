#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,tt,a[5005];
void solve()
{
        cin>>n;
        tt=0;
        for(int i=1;i<=n;i++)
                cin>>a[i];
        for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                        if(a[i]>a[j])
                                tt++;
        tt+=n/2;
        cout<<(tt&1?"Alice":"Bob")<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
