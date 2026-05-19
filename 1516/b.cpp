#include <bits/stdc++.h>
using namespace std;
int n,a[1<<11];
void solve() 
{
        cin>>n;
        int xr=0;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                xr^=a[i];
        }
        if(!xr)
        {
                cout<<"YES\n";
                return;
        }
        int rxr=0;
        for(int i=0;i<n-2;i++)
        {
                rxr^=a[i];
                int rxrr=0;
                for(int j=i+1;j<n-1;j++)
                {
                        rxrr^=a[j];
                        if((rxr==rxrr)&&(rxrr==(xr^rxrr^rxr)))
                        {
                                cout<<"YES\n";
                                return;
                        }
                }
        }
        cout<<"NO\n";
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
