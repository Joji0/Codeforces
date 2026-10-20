#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[200005],b[200005],ok;
void solve()
{
        cin>>n;
        ok=1;
        for(int i=1;i<=n;i++)
                cin>>a[i],b[a[i]]=i&1;
        if(n==1)
        {
                cout<<"YES\n";
                return;
        }
        for(int i=n;i>=2;i-=2)
                ok&=b[i]!=b[i-1];
        cout<<(ok?"YES":"NO")<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
