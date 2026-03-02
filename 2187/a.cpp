#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[1<<20],b[1<<20];
void solve() 
{
        cin>>n; 
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                b[i]=a[i];
        }
        bool ok=true;
        for(int i=0;i<n-1;i++)ok&=(a[i]<=a[i+1]);
        if(ok)
        {
                cout<<"-1\n";
                return;
        }
        int64_t mx=1LL<<60;
        sort(b,b+n);
        for(int i=0;i<n;i++)
        {
                if(a[i]!=b[i])mx=min(mx,max(a[i]-b[0],b[n-1]-a[i]));
        }
        cout<<mx<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
