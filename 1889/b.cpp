#include <bits/stdc++.h>
using namespace std;
int n;
int64_t c;
array<int64_t,2>a[1<<20];
void solve() 
{
        cin>>n>>c;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i][0];
                a[i][1]=i;
        }
        sort(a+2,a+n+1,[](const auto &x, const auto &y){return x[1]*c-x[0]<y[1]*c-y[0];});
        int64_t csum=a[1][0];
        bool ok=true;
        for(int i=2;i<=n;i++)
        {
                ok&=(csum+a[i][0]>=a[i][1]*c);
                csum+=a[i][0];
        }
        cout<<(ok?"Yes\n":"No\n");
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
