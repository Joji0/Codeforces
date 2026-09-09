#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
        cin>>n;
        bool ok=false;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
                int a;cin>>a;
                ok|=(a>=3);
                cnt+=bool(a>=2);
        }
        ok|=(cnt>1);
        cout<<(ok?"YES\n":"NO\n");
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
