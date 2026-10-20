#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[100005],b[100005],c[100005],d[100005],p;
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
                cin>>a[i],c[i-1]=d[i-1]=0;
        p=0;
        for(int i=1;i<=n;i++)
        {
                int l=a[i]*i,r=min(n,(a[i]+1)*i);
                c[l]++;
                c[r]--;
        }
        d[0]=c[0];
        for(int i=1;i<n;i++)
                d[i]=d[i-1]+c[i];
        for(int i=0;i<n;i++)
                if(!d[i])
                        b[p++]=i;
        cout<<p<<'\n';
        for(int i=0;i<p;i++)
                cout<<b[i]<<" \n"[i==p-1];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
