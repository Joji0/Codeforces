#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[200005],z;
void solve()
{
        z=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                if(!a[i])
                        z++;
        }
        if(z==1)
        {
                cout<<"NO\n";
                return;
        }
        cout<<"YES\n";
        int c=0;
        for(int i=1;i<=n;i++)
        {
                if(c==0&&!a[i])
                {
                        cout<<"A";
                        c++;
                }
                else if(!a[i])
                        cout<<"B";
                else
                        cout<<"C";
        }
        cout<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
