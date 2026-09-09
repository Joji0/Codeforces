// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int64_t a[N],d[N];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++)d[i]=a[i+1]-a[i];
        int i=1;
        while(i<n)
        {
                int j=i;
                while(j<n&&abs(d[j]&1)==abs(d[i]&1))j++;
                sort(d+i,d+j);
                i=j;
        }
        cout<<a[1]<<" ";
        int64_t nw=a[1];
        for(i=1;i<n;i++)
        {
                nw+=d[i];
                cout<<nw<<" ";
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
