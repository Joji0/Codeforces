#include <bits/stdc++.h>
using namespace std;
int n,a[1<<5];
void solve() 
{
        cin>>n; 
        for(int i=0;i<n;i++)cin>>a[i];
        bool ok=true;
        for(int i=0;i<n-1;i++)ok&=(a[i]<=a[i+1]);
        if(ok)
        {
                cout<<n<<'\n';
        }
        else 
        {
                cout<<"1\n";
        }
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
