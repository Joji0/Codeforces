#include <bits/stdc++.h>
using namespace std;
int n;
int64_t m,k,a[1<<20];
void solve() 
{
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        reverse(a,a+n);
        int64_t mxa=a[0],mxb=a[1],mul=m/(k+1),lf=m%(k+1);
        cout<<mul*mxa*k+mul*mxb+lf*mxa<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
